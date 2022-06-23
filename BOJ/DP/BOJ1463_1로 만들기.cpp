#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000005];
int main() {
	int n;
	cin >> n; 
	dp[1] = 0; 
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i < n + 1; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0)dp[i] = min(dp[i / 2] + 1, dp[i]);
	}
	cout << dp[n] << '\n';
	return 0;
}