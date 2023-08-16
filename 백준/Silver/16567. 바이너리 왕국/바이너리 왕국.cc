#include<iostream>
using namespace std;
int n, m, arr[1000005], cnt, a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i]) {
			cnt++;
			if (arr[i - 1])cnt--;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (!a)cout << cnt << '\n';
		else {
			cin >> b;
			if (!arr[b-1]) {
				arr[b - 1] = 1;
				if (!arr[b - 2] && !arr[b])cnt++;
				else if (arr[b - 2] && arr[b])cnt--;
			}
		}
	}
}