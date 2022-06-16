#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<pair<int, int>, int>p;
int ansmin, ansmax, mini = -1e9, maxi = 1e9, t, cnt;
int arr[101], a[101], b[101];
string str[101];
int main() {
	cin >> t;
	for (int i = 0; i < t; i++)	cin >> str[i] >> a[i] >> b[i];
	for (int i = t - 1; i >= 0; i--) {
		if (str[i] == "none") {
			mini = max(mini, a[i]);
			maxi = min(maxi, b[i]);
		}
		else if (str[i] == "off") {
			mini += a[i], maxi += b[i];
		}
		else {
			mini -= b[i], maxi -= a[i];
			mini = max(mini, 0);
		}
	}
	cout << mini << ' ' << maxi << "\n";
	mini = -1e9, maxi = 1e9;
	for (int i = 0; i < t; i++) {
		if (str[i] == "none") {
			mini = max(mini, a[i]);
			maxi = min(maxi, b[i]);
		}
		else if (str[i] == "off") {
			mini -= b[i], maxi -= a[i];
			mini = max(mini, 0);

		}
		else {
			mini += a[i], maxi += b[i];
		}
	}
	cout << mini << ' ' << maxi << "\n";
	return 0;
}