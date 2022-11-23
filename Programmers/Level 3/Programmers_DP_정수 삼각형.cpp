#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>>dp; //triangle�� Ÿ�� ������ �� �ִ밪�� ����� ����Ʈ
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	dp.resize(triangle.size());
	int s = triangle.size();
	for (int i = 0; i < s; i++) dp[i].resize(triangle[i].size()); 
	dp[0][0] = triangle[0][0];
	dp[0].push_back(dp[0][0]); 
	//dp[0][1]=dp[0][0] why? ����ó�� ���� ���ֱ� �Ⱦ �߰�. 
	//������ depth 2������ dp[0][0]�� �����ϱ⿡ dp[0][1]�� ���� ���� �־ ����� ����
	for (int i = 1; i < s; i++) {
		dp[i][0] = triangle[i][0] + dp[i - 1][0]; 
		dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];
		//�� ���� 1���� ���������� ���� ���� 1���� ���������� Ÿ�� ���� ��Ʈ�� �����Ƿ� ���� ó��
		for (int j = 1; j < triangle[i].size() - 1; j++) {
			dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			//���� ���� ���ʰ� ������ ���� ū �� + ���� ��ġ�� triangle �迭�� ���� ���Ѵ�
		}
	}
	for (int i = 0; i < s; i++) {
		answer = max(answer, dp[s - 1][i]);
	}
	return answer;
}