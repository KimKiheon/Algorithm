#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef struct Pos {
	int pos, idx;
	
}p;
struct compare{
	bool operator()(const Pos &p1, const Pos &p2) {
		return p1.pos > p2.pos;
	}
};
vector<p>x, y, z;
vector<vector<p>>edge;
int n, check[100005], ans;
bool cmp(const Pos& p1, const Pos &p2) {
	return p1.pos > p2.pos;
 }
priority_queue<p, vector<p>, compare>pq;
void input() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	edge.resize(n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a,i });
		y.push_back({ b,i });
		z.push_back({ c,i });
	}
	sort(x.begin(), x.end(),cmp);
	sort(y.begin(), y.end(),cmp);
	sort(z.begin(), z.end(),cmp);

	for (int i = 1; i != x.size(); i++) {
		edge[x[i].idx].push_back({ abs(x[i].pos - x[i - 1].pos), x[i - 1].idx });
		edge[x[i - 1].idx].push_back({ abs(x[i].pos - x[i - 1].pos), x[i].idx });
		edge[y[i].idx].push_back({ abs(y[i].pos - y[i - 1].pos), y[i - 1].idx });
		edge[y[i - 1].idx].push_back({ abs(y[i].pos - y[i - 1].pos), y[i].idx });
		edge[z[i].idx].push_back({ abs(z[i].pos - z[i - 1].pos), z[i - 1].idx });
		edge[z[i - 1].idx].push_back({ abs(z[i].pos - z[i - 1].pos), z[i].idx });
	}
}
void prim() {
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int now = pq.top().idx, cost = pq.top().pos;
		pq.pop();
		if (check[now])continue;
		check[now] = 1;
		ans += cost;
		for (p pp : edge[now]) {
			int next = pp.idx, ncost = pp.pos;
			if (!check[next])pq.push({ ncost,next });
		}
	}
}
int main() {
	input();
	prim();
	cout << ans << "\n";
}