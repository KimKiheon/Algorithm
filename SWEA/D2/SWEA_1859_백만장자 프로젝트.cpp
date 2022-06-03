#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		vector<int>v;
		int n, maxi = 0;
		long long sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		maxi = v.back();
		for (int i = v.size() - 2; i >= 0; i--) {
			if (v[i] < maxi)sum += maxi - v[i];
			else if (v[i] > maxi)maxi = v[i];
		}
		cout << "#" << tc + 1 << " " << sum << "\n";
	}
	return 0;
}