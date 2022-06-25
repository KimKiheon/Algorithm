#include <iostream>
#include <algorithm>
using namespace std;
int dp[505][505];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> dp[i][j];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int now = dp[i][j];
			dp[i][j] = max(now + dp[i - 1][j - 1], now + dp[i - 1][j]);
		}

	}
	int maxi = dp[n][1];
	for (int i = 2; i <= n; i++)maxi = max(maxi, dp[n][i]);
	cout << maxi << "\n";
	return 0;
}