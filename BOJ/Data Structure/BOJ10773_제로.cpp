#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int> s;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (!a)s.pop();
		else s.push(a);
	}
	while(!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans << "\n";
	return 0;
}