#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef double d;
typedef pair<d, pair<d, d>>p;
priority_queue<p, vector<p>, greater<p>>pq;
typedef pair<d, d>pp;
vector<pp>v;
vector<vector<pp>>vv;
int n, pa[105];
d ans;
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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vv.resize(n + 1);
	for (int i = 0; i < n; i++) {
		d x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	for (int i = 0; i < n; i++)pa[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			d x = abs(v[j].first - v[i].first);
			d y = abs(v[j].second - v[i].second);
			d r = sqrt(pow(x, 2) + pow(y, 2));
			pq.push({ r,{i,j} });
		}
	}
	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();
		d a = now.second.first, b = now.second.second, c = now.first;
		if (f(a) != f(b)) {
			u(a, b);
			ans += c;
		}
	}
	printf("%.3lf", ans);
	return 0;
}