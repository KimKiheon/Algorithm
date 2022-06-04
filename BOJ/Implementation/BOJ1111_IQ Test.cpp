#include<iostream>
using namespace std;
bool check = true;
int main() {
	int n, arr[51], b, x, y, a;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n == 1) cout << "A";
	else if (n == 2) {
		if (arr[0] == arr[1]) cout << arr[0];
		else cout << "A";
	}
	else {
		a = 0;
		x = arr[1] - arr[0];
		y = arr[2] - arr[1];
		if (x != 0) a = y / x;
		b = arr[1] - a * arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] != (arr[i - 1] * a + b)) {
				check = false;
				break;
			}
		}
		if (check) cout << arr[n - 1] * a + b;
		else cout << "B";
	}
	return 0;
}