#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int visit[1005], n, m, s;
queue<int>q;
vector<vector<int>>v;
void dfs(int now) {
	visit[now] = 1;
	cout << now << " ";
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}
void bfs(int start) {
	visit[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		visit[now] = 1;
		cout << now << " ";
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!visit[next]) {
				visit[next] = 1;
				q.push(next);
			}
		}
	}
}
int main() {
	cin >> n >> m >> s;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)sort(v[i].begin(), v[i].end());
	dfs(s);
	cout << "\n";
	memset(visit, 0, sizeof(visit));
	bfs(s);
	return 0;
}