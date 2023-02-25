#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
int n, m, ans = 21e8;
int arr[100005];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int tmp = *lower_bound(arr, arr + n, arr[i] + m);
		if (!tmp)continue;
		ans = min(ans, tmp - arr[i]);
	}
	cout << ans << "\n";
	return 0;
}