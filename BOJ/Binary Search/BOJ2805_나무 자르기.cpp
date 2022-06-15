#include<iostream>
#include<algorithm>
using namespace std;
long long n, key, maxi, arr[1000005], l, r, mid, ans, sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> key;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}
	l = 0, r = maxi;
	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) if (arr[i] - mid > 0)sum += arr[i] - mid;
		if (sum < key)r = mid - 1;
		else l = mid + 1;
	}
	cout << r;
}