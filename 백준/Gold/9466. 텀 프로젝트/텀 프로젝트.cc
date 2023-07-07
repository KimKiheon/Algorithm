#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int t, n, arr[100005], check[100005];
vector<int>v;
int main() {
	ios_base::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		int cnt = 0;
		v.clear();
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			int j = i;
			vector<int> path;
			while (!check[j]) {
				check[j] = 1;
				path.push_back(j);
				j = arr[j];
			}
			auto k = find(path.begin(), path.end(), j);
			cnt += distance(path.begin(), k);
		}
		cout << cnt << "\n";
	}
}