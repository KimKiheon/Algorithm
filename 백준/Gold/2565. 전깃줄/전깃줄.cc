#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, a, b, ans, arr[505],x[105];
vector<int>v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[a] = b;
		x[i] = a;
	}
	sort(x, x + n);
	v.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (v.back() < arr[x[i]]) {
			v.push_back(arr[x[i]]);
			ans++;
		}
		else {
			auto k = lower_bound(v.begin(), v.end(), arr[x[i]]);
			*k = arr[x[i]];
		}
	}
	cout << n - ans;
	return 0;
}