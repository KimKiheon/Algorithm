#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
typedef pair<int, int>p;
vector<vector<p>>v;
queue<p>q;
int n;
int dist[100005], visited[100005], maxi,s2;
void bfs(int start) {
	q.push({ start,0 });
	while (!q.empty()) {
		int now = q.front().first;
		int nowc = q.front().second;
		maxi = max(maxi, nowc);
		dist[now] += nowc;
		q.pop();
		visited[now] = 1;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			if (!visited[next]) {
				q.push({ next,dist[now]+v[now][i].second});
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d", &a);
		while (1) {
			scanf("%d", &b);
			if (b == -1)break;
			scanf("%d", &c);
			v[a].push_back({ b,c });
		}
	}
	bfs(1);
	for (int i = 1; i <= n; i++)if (maxi == dist[i])s2 = i;
	memset(dist, 0, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	bfs(s2);
	printf("%d\n",maxi);
	return 0;
}