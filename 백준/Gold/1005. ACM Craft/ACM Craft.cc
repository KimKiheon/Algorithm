#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int n, m, t, ind[1001], time[1001], addtime[1001], key;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		vector<vector<int>>v(n+1);
		queue<int>q;
		memset(ind, 0, sizeof(ind));
		memset(time, 0, sizeof(time));
		memset(addtime, 0, sizeof(addtime));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &time[i]);
			addtime[i] = time[i];
		}
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			ind[b]++;
		}
		scanf("%d", &key);
		for (int i = 1; i <= n; i++)if (!ind[i])q.push(i);
		while (!q.empty()) {
			int now = q.front();
			if (now == key)break;
			q.pop();
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i];
				addtime[next] = max(addtime[next], addtime[now] + time[next]);
				ind[next]--;
				if (!ind[next])q.push(next);
			}
		}
		printf("%d\n", addtime[key]);
	}
	return 0;
}