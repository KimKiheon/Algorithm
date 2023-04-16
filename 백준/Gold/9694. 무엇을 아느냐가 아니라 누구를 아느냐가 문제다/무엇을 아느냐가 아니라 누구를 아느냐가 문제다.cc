#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;
#define INF 2e9
typedef pair<int, int>p;
int n, m, tc = 1;
vector<p>v[21];
int path[20], dist[20];
void input() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		v[i].clear();
		path[i] = -1;
		dist[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
}
void dijk() { //다익스트라
	priority_queue<p>pq;
	pq.push({ 0,0 });
	dist[0] = 0;
	while (!pq.empty()) {
		int now = pq.top().second, c = -pq.top().first;
		pq.pop();
		if(dist[now] < c) continue;
		for (p pp:v[now]) {
			int next = pp.first, ncost = pp.second;
			if (dist[next] > c + ncost) {
				dist[next] = c + ncost;
				pq.push({ -dist[next],next });
				path[next] = now; //최단경로 갱신시 경로 저장
			}
		}
	}
}

void print() {
	cout << "Case #" << tc++ << ":";
	if (dist[n - 1] == INF) {
		cout << " -1" << "\n";
		return;
	}
	int idx = n - 1;

	vector<int>tmp;

	//경로 역추적
	tmp.push_back(n - 1);
	while (idx!=0) {
		tmp.push_back(idx = path[idx]);
	}
	for (int i = tmp.size() - 1; i >= 0; i--)cout << " " << tmp[i];
	cout << "\n";
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		input();
		dijk();
		print();
	}
	return 0;
}