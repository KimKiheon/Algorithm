#include<iostream>
#include<algorithm>
using namespace std;
int n;
int dp[1005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> dp[i];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}