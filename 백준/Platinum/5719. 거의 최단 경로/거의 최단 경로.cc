#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int, int>p;
#define INF 1e9
vector<vector<p>>pv;
priority_queue<p>pq;
int dist[501];
vector<vector<int>>path;
int v, e, from, to, a, b, c, mini = INF;
int dijk(int start) {
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < pv[now].size(); i++) {
			int next = pv[now][i].first;
			int nxcost = dist[now] + pv[now][i].second;
			if (pv[now][i].second == -1)continue;
			if (dist[next] > nxcost) {
				dist[next] = nxcost;
				path[next].clear();
				path[next].push_back(now);
				pq.push({ -dist[next],next });
			}
			else if (dist[next] == nxcost) {
				path[next].push_back(now);
			}
		}
	}
	return dist[to];
}
void go(int aa) {
	queue<int>q;
	q.push(aa);
	bool check[501]= { false, };
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (check[now])continue;
		check[now] = 1;
		for (int i = 0; i < path[now].size(); i++) {
			int next = path[now][i];
			for (int j = 0; j < pv[next].size(); j++) {
				if (pv[next][j].first == now) pv[next][j].second = -1; // 간선을 삭제
			}
			q.push(next);
		}
		
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (1) {
		pv.clear();
		path.clear();
		cin >> v >> e;
		if (!v && !e)return 0;
		pv.resize(v + 1);
		path.resize(v + 1);
		cin >> from >> to;
		for (int i = 0; i < e; i++) {
			cin >> a >> b >> c;
			pv[a].push_back({ b,c });
		}
		fill(dist, dist + 501, INF);
		int mini = dijk(from);

		go(to);
		path.clear();
		path.resize(v + 1);
		fill(dist, dist + 501, INF);
		int temp = dijk(from);
		if (mini != temp && temp != INF) {
			cout << temp << "\n";
		}
		if (dist[to] == INF) {
			cout << -1 << "\n";
		}
	}
	return 0;
}