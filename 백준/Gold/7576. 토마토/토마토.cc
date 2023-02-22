#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int>p;
queue<p>q;
bool check;
bool chk;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 }, arr[1005][1005];
int n, m, cnt, maxi = -2;
void bfs() {
	while (!q.empty()) {
		p now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i], ny = now.second + dy[i];
			if (0 <= nx&&nx < n && 0 <= ny&&ny < m&&arr[nx][ny] == 0) {
				arr[nx][ny] = arr[now.first][now.second] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)q.push({ i,j });
		}
	bfs();
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
		if (arr[i][j] == 0) {
			printf("-1");
			return 0;
		}
		maxi = max(maxi, arr[i][j]);
	}
		printf("%d", maxi-1);
		return 0;
}