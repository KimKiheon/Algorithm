#include<iostream>
#include<algorithm>
#include<vector>
int n, ans = 0, arr[1000], dp[1000];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int idx = 0;
	dp[idx++] = arr[0];
	for (int i = 1; i < n; i++) {
		if (dp[idx - 1] < arr[i])dp[idx++] = arr[i];
		else if (dp[idx - 1] > arr[i]) {
			dp[lower_bound(dp, dp + idx, arr[i]) - dp] = arr[i];
		}
	}
	cout << idx << "\n";
	return 0;
}