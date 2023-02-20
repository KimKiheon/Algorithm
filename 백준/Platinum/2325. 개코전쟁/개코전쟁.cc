#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef pair<int, int>P;
vector<vector<P>>pv;
priority_queue<P>pq;
const int INF = 987654321;
int node, line, from, to, cost;
int maximum, dist[1001], previ[1001], ans = 0;
vector<int>check;
void dijk(int start, int last) {
	fill(dist, dist + node + 1, INF);
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost)continue;
		for (int i = 0; i < pv[now].size(); i++) {
			int next = pv[now][i].second;
			if (dist[next] > cost + pv[now][i].first) {
				dist[next] = cost + pv[now][i].first;
				pq.push({ -dist[next],next });
				previ[next] = now;
			}
		}
	}
}
int dijk2(int u, int v) {
	fill(dist, dist + node + 1, INF);
	dist[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost)continue;
		for (int i = 0; i < pv[now].size(); i++) {
			int next = pv[now][i].second;
			if ((now == u && next == v) || (now == v && next == u))continue;
			if (dist[next] > cost + pv[now][i].first) {
				dist[next] = cost + pv[now][i].first;
				pq.push({ -dist[next],next });
			}
		}
	}
	return dist[node];
}
int main() {

	cin >> node >> line;
	pv.resize(node + 1);
	check.reserve(node + 1);
	for (int i = 0; i < line; i++) {
		cin >> from >> to >> cost;
		pv[from].push_back({ cost,to });
		pv[to].push_back({ cost,from });
	}
	dijk(1, node);
	for (int i = node;; i = previ[i]) {
		ans = max(ans, dijk2(previ[i], i));
		if (previ[i] == 1)break;
	}
	cout << ans;
	return 0;
}