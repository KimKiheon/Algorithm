#include<iostream>
#include<string.h>
using namespace std;
int t, n, ans, maxi, arr[100005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 1;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			arr[a] = b;
		}
		maxi = arr[1];
		for (int i = 2; i <= n; i++) {
			if (arr[i] < maxi) {
				ans++;
				maxi = arr[i];
			}
		}
		cout << ans << '\n';
	}
}