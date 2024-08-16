#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int arr[100005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, s, ans = 100005;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > s) {
			cout << 1;
			return 0;
		}
	}

	int i, j; 
	i = j = 0;
	//i가 n보다 작을 때까지
	ll sum = arr[0];
	bool flag = false;
	while (i < n) {
		while (sum < s) {
			sum += arr[++j];
			if (j == n && sum < s) {
				flag = true;
				break;
			}
		}
		if (flag) break;
		while (sum - arr[i] >= s) {
			sum -= arr[i++];
		}
		ans = min(ans, j - i + 1);
		sum -= arr[i++];
	}
	if (ans == 100005) cout << 0;
	else cout << ans;
}