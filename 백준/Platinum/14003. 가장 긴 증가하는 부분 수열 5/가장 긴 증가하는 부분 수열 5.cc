#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
int n, ans, parent[1000005], ii;
pair<int, int> arr[1000005];
vector<int>v;
stack<int>s;
#define I -1111111111
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	v.push_back(I);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (v.back() < x) {
			v.push_back(x);
			arr[i] = { ii,x };
			parent[ii++] = v.back();
			ans++;
		}
		else {
			auto k = lower_bound(v.begin(), v.end(), x);
			*k = x;
			auto z = k - v.begin()-1;
			parent[z] = x;
			arr[i] = { z,x };
		}
	}
	ii--;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i].first == ii) {
			s.push(arr[i].second);
			ii--;
		}
	}
	cout << ans << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
}