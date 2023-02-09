#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n;
vector<vector<int>> v;
queue<int>q;
int indegree[10001];
int time[100001];
vector<int>turn;
void bfs() {
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push(i);
			turn[i] = time[i];
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int number = v[now].size();
		for (int i = 0; i < number; i++) {
			int next = v[now][i];
			indegree[next]--;
			turn[next]=max(turn[next], turn[now] + time[next]);
			if (!indegree[next])
				q.push(next);
		}
	}
}
int main() {
	scanf("%d", &n);
	v.resize(n+1);
	turn.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &time[i]);
		int num;
		scanf("%d", &num);//선행작업 갯수
		while (num--) {
			int t;
			scanf("%d", &t);
			v[t].push_back(i);
			indegree[i]++;
		}
	}
	bfs();
	sort(turn.begin(),turn.end());
	printf("%d", turn[n]);
	return 0;
}