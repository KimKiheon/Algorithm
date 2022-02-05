#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int>v;
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a <= m)v.push_back(a);
	}
	while (m) {
		if (m - v.back() >= 0) {
			m -= v.back();
			cnt++;
		}
		else v.pop_back();
	}
	cout << cnt << "\n";
	return 0;
}