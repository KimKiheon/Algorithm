#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[1005];
int main() {
	int tc = 0;
	while (tc++ != 10) {
		int n, ans = 0;
		int leftmax, rightmax;
		cin >> n;
		for (int i = 2; i < n + 2; i++) {
			cin >> arr[i];
		}
		for (int i = 2; i < n + 2; i++) {
			leftmax = rightmax = 0;
			rightmax = max(arr[i + 1], arr[i + 2]);
			leftmax = max(arr[i - 1], arr[i - 2]);
			if (leftmax <= arr[i] && rightmax <= arr[i]) {
				ans += arr[i] - max(rightmax, leftmax);
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}