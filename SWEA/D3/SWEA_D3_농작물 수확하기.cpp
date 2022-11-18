#include<iostream>
using namespace std;
int main() {
	int t, TC = 0;
	cin >> t;
	while (TC++ < t) {
		int arr[50][50];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)scanf_s("%1d", &arr[i][j]);
		}
		int mid = n / 2;
		int cnt = 1, ans = arr[0][mid];
		for (int i = 1; i <= mid; i++) {
			for (int j = 1; j <= cnt; j++) {
				ans += arr[i][mid + j] + arr[i][mid - j];
			}
			ans += arr[i][mid];
			cnt++;
		}
		for (int i = mid + 1; i < n-1; i++) {
			--cnt;
			for (int j = cnt - 1; j >= 1; j--) {
				ans += arr[i][mid + j] + arr[i][mid - j];
			}
			ans += arr[i][mid];
		}
		ans += arr[n - 1][mid];
		cout << "#" << TC << " " << ans;
	}
	return 0;
}