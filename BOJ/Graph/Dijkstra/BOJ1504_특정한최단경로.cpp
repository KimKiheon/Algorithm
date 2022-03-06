#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include<functional>
using namespace std;
typedef pair<int, int>P;
const int INF = 987654321;
int node, line, to, from, cost, d1, d2, cnt;
int dist[801], result1, result2, result;
vector<vector<P>>pv;
priority_queue<P>pq;
int dijk(int start, int last) {
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
			}
		}
	}
	return dist[last];
}
int main() {
	scanf("%d %d", &node, &line);
	pv.resize(node + 1);
	for (int i = 0; i < line; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		pv[from].push_back({ cost,to });
		pv[to].push_back({ cost,from });
	}
	scanf("%d %d", &d1, &d2);
	result1 = dijk(1, d1) + dijk(d1, d2) + dijk(d2, node);
	result2 = dijk(1, d2) + dijk(d2, d1) + dijk(d1, node);
	result = min(result1, result2);
	if (result >= INF || result < 0)
		printf("-1");
	else
		printf("%d", result);
	return 0;
}