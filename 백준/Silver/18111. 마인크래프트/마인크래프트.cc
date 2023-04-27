#include<iostream>
#include<algorithm>
using namespace std;
int n, m, b, ans1=2e9, ans2 = 257;
int arr[505][505];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int h = 0; h <= 256; h++) {
		int cnt = b, time = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > h) {
					int tmp = arr[i][j] - h;
					cnt += tmp;
					time += 2 * tmp;
				}
				else if (arr[i][j] < h) {
					int tmp = h - arr[i][j];
					cnt -= tmp;
					time += tmp;
				}
			}
		}
		if (cnt < 0) continue;
		if (ans1 > time) {
			ans1 = time;
			ans2 = h;
		}
		else if (ans1 == time) ans2 = h;
	}
	cout << ans1 << " " << ans2;
	return 0;
}