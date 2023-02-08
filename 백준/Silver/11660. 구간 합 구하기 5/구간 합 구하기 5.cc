#include<iostream>
using namespace std;
int arr[1025][1025];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			arr[i][j] = arr[i][j - 1] + a;
		}
	}
	while (m--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int sum = 0;
		if (x1 == x2) {
			cout<< arr[x2][y2] - arr[x2][y1 - 1]<<"\n";
			continue;
		}
		for (int i = x1; i <= x2; i++) {
			sum += arr[i][y2] - arr[i][y1 - 1];
		}
		cout << sum << "\n";
	}
	return 0;
}