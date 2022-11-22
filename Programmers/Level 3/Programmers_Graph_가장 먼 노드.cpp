#include<string>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>>v;
queue<int>q;
int maxi, answer;
int dist[20005];
void bfs() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!dist[next]) {
				dist[next] = dist[now] + 1;
				q.push(next);
				maxi = max(maxi, dist[next]);
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	v.resize(n + 1);
	for (int i = 0; i < edge.size(); i++) {
		for (int j = 0; j < 2; j++) {
			int a = edge[i][0], b = edge[i][1];
			v[a].push_back(b);
			v[b].push_back(a);
		}
	}
	dist[1] = 1;
	q.push(1);

	bfs();

	for (int i = 1; i <= n; i++) if (dist[i] == maxi) answer++;
	return answer;
}