#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, pair<int, int>>p;
priority_queue<p, vector<p>, greater<p>>pq;
int n, m, pa[100005], ans, last;
int f(int x) {
	if (pa[x] == x)return x;
	pa[x] = f(pa[x]);
	return pa[x];
}
void u(int a, int b) {
	a = f(a);
	b = f(b);
	if (a == b)return;
	pa[b] = a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)pa[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}
	while (!pq.empty()) {
		p e = pq.top();
		pq.pop();
		int a = e.second.first, b = e.second.second, c = e.first;
		if (f(a) != f(b)) {
			u(a, b);
			ans += c;
			last = c;
		}
	}
	cout << ans-last << '\n';
}