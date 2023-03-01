#include<iostream>
#include<vector>
using namespace std;
int n, m, parent[201], s;
vector<int>path;
int f(int a) {
	if (parent[a] == a)return a;
	parent[a] = f(parent[a]);
	return parent[a];
}
void u(int a, int b) {
	a = f(a);b = f(b);
	if (f(a) == f(b))return;
	parent[b] = a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)parent[i] = i;
	path.resize(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			if (x == 1)u(i, j);
		}
	}
	for (int i = 0; i < m; i++)cin >> path[i];
	int s = f(parent[path[0]]);
	for (int i = 0; i < m; i++) {
		if (s != f(parent[path[i]])) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}