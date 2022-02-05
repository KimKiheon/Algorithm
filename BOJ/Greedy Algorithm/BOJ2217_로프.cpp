#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, sum = 0, ans = 0;
	int arr[100005];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i] * (n - i));
	}
	cout << ans << "\n";
	return 0;
}
