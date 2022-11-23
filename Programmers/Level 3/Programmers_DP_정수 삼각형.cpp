
#include<vector>
#include<algorithm>

using namespace std;
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int s = triangle.size();

	triangle[0].push_back(triangle[0][0]);
	//triangle[0][1]=dp[0][0] why? ����ó�� ���� ���ֱ� �Ⱦ �߰�. 
	//������ depth 2������ triangle[0][0]�� �����ϱ⿡ triangle[0][1]�� ���� ���� �־ ����� ����

	for (int i = 1; i < s; i++) {
		triangle[i][0] = triangle[i][0] + triangle[i - 1][0];
		triangle[i][i] = triangle[i][i] + triangle[i - 1][i - 1];
		//�� ���� 1���� ���������� ���� ���� 1���� ���������� Ÿ�� ���� ��Ʈ�� �����Ƿ� ���� ó��
		for (int j = 1; j < triangle[i].size() - 1; j++) {
			triangle[i][j] = triangle[i][j] + max(triangle[i - 1][j], triangle[i - 1][j - 1]);
			//���� ���� ���ʰ� ������ ���� ū �� + ���� ��ġ�� triangle �迭�� ���� ���Ѵ�
		}
	}

	for (int i = 0; i < s; i++) answer = max(answer, triangle[s - 1][i]);

	return answer;
}