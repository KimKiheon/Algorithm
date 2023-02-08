#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>>v;
bool visited[102000];
#define MAX 100001
#define INF 1e9
queue<int>q;
int n, k, m, ans,dist[102000],a;
bool check;
void bfs(int s) {
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == n) {
			ans = dist[n];
			return;
		}
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!visited[next])
				if (next <= n) {
					visited[next] = 1;
					q.push(next);
					dist[next] = dist[now] + 1;
				}
				else {
					q.push(next);
					dist[next] = dist[now];
				}
		}
	}
	check = true;
	return;
}
int main() {
	scanf("%d %d %d",&n,&k,&m);
	if (n == 1) {
		printf("1");
		return 0;
	}
	v.resize(n + m + 1);
	for (int i = n + 1; i < n + m + 1; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d ",&a);
			v[i].push_back(a);
			v[a].push_back(i);
		}
	}
	bfs(1);
	if (check)printf("-1");
	else printf("%d",ans+1);
}