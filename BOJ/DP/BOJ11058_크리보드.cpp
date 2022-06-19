#include<iostream>
#include<algorithm>
using namespace std;
int n;
typedef long long ll;
ll dp[105];
int main() {
	cin >> n;
	for (int i = 1; i <= 6; i++)dp[i] = i;
	for (int i = 7; i <= n; i++) {
		for (int j = 1; j <= i - 3; j++)
			dp[i] = max(dp[i], max(dp[i - 1] + 1, dp[i - (j + 2)] * (j + 1)));
	}
	cout << dp[n];
	return 0;
}