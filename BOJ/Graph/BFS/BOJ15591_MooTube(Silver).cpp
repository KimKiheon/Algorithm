#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int n, q;
typedef pair<int, int>p;
vector<vector<p>>v;
int visited[5005];
int main() {
	cin >> n >> q;
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 0; i < q; i++) {
		int k, start, cnt = 0;
		cin >> k >> start;
		queue<int>q;
		q.push(start);
		memset(visited, 0, sizeof(visited));
		while (!q.empty()) {
			int now = q.front();
			visited[now] = 1;
			q.pop();
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i].first;
				int cost = v[now][i].second;
				if (!visited[next] && cost >= k) {
					q.push(next);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}