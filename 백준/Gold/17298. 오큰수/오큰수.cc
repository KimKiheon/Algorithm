#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> arr(n),ans(n,-1);
	stack<int> s;
	for (int i = 0, t = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 0; i < n ; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			ans[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}