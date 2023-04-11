#include<iostream>
using namespace std;
int n, m, cnt;
int parent[100005];
int find(int x) {
	if (x == parent[x])return x;
	return parent[x] = find(parent[x]);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	while (m--) {
		int a;
		cin >> a;
		int b = find(a);
		if (!b)break;
		cnt++;
		parent[b] = b - 1;
	}
	cout << cnt << "\n";
	return 0;
}