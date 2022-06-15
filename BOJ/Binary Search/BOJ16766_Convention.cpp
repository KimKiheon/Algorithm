#include<iostream>
#include<algorithm>
using namespace std;
int n, m, c;
int arr[100005];
int check(int x) {
	int f = 1, idx = 0;
	int a = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - a > x || i - idx + 1 > c) {
			f++;
			a = arr[i];
			idx = i;
		}
	}
	if (f <= m)return 1;
	else return 0;
}
int main() {
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	int left = 0, right = 1e9;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (left == right) {
			mid = left;
			break;
		}
		if (left == right - 1) {
			if (check(left)) {
				mid = left;
				break;
			}
			else {
				mid = right;
				break;
			}
		}
		if (check(mid))right = mid;
		else left = mid + 1;
	}
	cout << mid << "\n";
}