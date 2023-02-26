#include<iostream>
#include<algorithm>
using namespace std;
int n,maxi=-2e9,mini=2e9;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		maxi = max(maxi, a);
		mini = min(mini, a);
	}
	cout << mini << " " << maxi << "\n";
	return 0;
}