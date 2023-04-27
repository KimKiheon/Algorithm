#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<climits>
using namespace std;
typedef long long ll;
const int INF = 25000000;
int n, m, from, to, cost, t, wh;
ll dist[501];
typedef pair<int, int>P;
vector<vector<P>>pv;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		pv.clear();
		bool cycle = false;
		cin >> n >> m >> wh;
		pv.resize(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> from >> to >> cost;
			pv[from].push_back({ cost,to });
			pv[to].push_back({ cost,from });
		}
		for (int i = 0; i < wh; i++) {
			cin >> from >> to >> cost;
			pv[from].push_back({ -cost,to });
		}
		fill(dist, dist + n + 1, 0);

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < pv[i].size(); j++) {
					int next = pv[i][j].second;
					int nextcost = pv[i][j].first;
					if (dist[i] != INF && dist[next] > dist[i] + nextcost) {
						dist[next] = dist[i] + nextcost;
						if (k == n)cycle = true;
					}
				}
			}
		}
		if (cycle)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}