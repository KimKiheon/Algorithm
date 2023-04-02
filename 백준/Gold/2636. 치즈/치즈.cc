#include<iostream>
#include<string.h>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int>p;
queue<p>q1;
queue<p>q2;
queue<p>rq;
int a[105][105], dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 }, time;
bool v[105][105];
int ans, n, m, cnt, xx;
void del() {
	xx = 0;
	while (!rq.empty()) {
		a[rq.front().first][rq.front().second] = 0;
		ans--;
		rq.pop();
		xx++;
	}
}
void bfs1(int x, int y) {
	q1.push({ x,y });
	v[x][y] = 1;
	while (!q1.empty()) {
		p now = q1.front();
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i], ny = now.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (!v[nx][ny] && !a[nx][ny]) {
				q1.push({ nx,ny });
				v[nx][ny] = 1;
			}
			else if (!v[nx][ny] && a[nx][ny]) {
				v[nx][ny] = 1;
				rq.push({ nx,ny });
			}
		}
	}
}
void bfs2(int x, int y) {
	q2.push({ x,y });
	v[x][y] = 1;
	while (!q2.empty()) {
		p now = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i], ny = now.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (!v[nx][ny] && a[nx][ny]) {
				q2.push({ nx,ny });
				v[nx][ny] = 1;
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j])ans++;
		}
	while (1) {
		time++;
		cnt = 0;
		bfs1(0, m / 2);
		del();
		memset(v, 0, sizeof(v));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!v[i][j] && a[i][j]) {
					bfs2(i, j);
					cnt++;
				}
		if (!cnt) {
			printf("%d\n", time);
			printf("%d", xx);
			return 0;
		}
		memset(v, 0, sizeof(v));
	}
}