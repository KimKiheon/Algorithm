#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		int n, m;
		bool flag = 1;
		cin >> n >> m;
		int tmp = (1 << n) - 1;
		tmp &= m;
		for (int i = 0; i < n; i++) {
			if (!(1 << i & tmp)) {
				flag = 0;
				break;
			}
		}
		cout << "#" << tc++ << " ";
		flag ? cout << "ON" << "\n" : cout << "OFF" << "\n";
	}
	return 0;
}
