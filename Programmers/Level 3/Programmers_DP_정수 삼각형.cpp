#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>>dp; //triangle을 타고 내려올 때 최대값을 기록할 리스트
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	dp.resize(triangle.size());
	int s = triangle.size();
	for (int i = 0; i < s; i++) dp[i].resize(triangle[i].size()); 
	dp[0][0] = triangle[0][0];
	dp[0].push_back(dp[0][0]); 
	//dp[0][1]=dp[0][0] why? 예외처리 따로 해주기 싫어서 추가. 
	//어차피 depth 2에서는 dp[0][0]만 참조하기에 dp[0][1]에 같은 값이 있어도 결과는 같다
	for (int i = 1; i < s; i++) {
		dp[i][0] = triangle[i][0] + dp[i - 1][0]; 
		dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];
		//각 행의 1열과 마지막열은 이전 행의 1열과 마지막열을 타고 오는 루트만 있으므로 따로 처리
		for (int j = 1; j < triangle[i].size() - 1; j++) {
			dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			//이전 행의 왼쪽과 오른쪽 값중 큰 값 + 현재 위치의 triangle 배열의 값을 더한다
		}
	}
	for (int i = 0; i < s; i++) {
		answer = max(answer, dp[s - 1][i]);
	}
	return answer;
}