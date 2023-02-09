#include<iostream>
#include<algorithm>
#include<string.h>
#include<utility>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int>p;
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 }, ans, n, m, cnt;
char arr[51][51];
bool visited[51][51], flag, check;
vector<p> w;
queue<pair<pair<int,int>,int>>wq;
queue<p>q;
p to, f, s;
void bfsw(int x,int y,int c) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx<0 || nx>n || ny<0 || ny>m)continue;
		if (arr[nx][ny] == '.') {
			visited[nx][ny] = 1;
			arr[nx][ny] = '*';
			wq.push({ {nx,ny},c + 1 });
		}
	}
}
void bfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		p now = { x,y };
		int nx = x + dx[i], ny = y + dy[i];
		if (arr[nx][ny] == 'D') {
			flag = true;
			return;
		}
		if (!visited[nx][ny] && arr[nx][ny] == '.') {
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &arr[i][j]);
			char a = arr[i][j];
			if (a == '*')wq.push({ { i,j },0 });
			else if (a == 'X')s={ i,j };
			else if (a == 'D')to = { i,j };
			else if (a == 'S') {
				f = { i,j };
				q.push({ i,j });
			}
		}
	}
	while (1) {
		ans++;
		int ss = q.size();
		int s = wq.size();
		if (!ss) break;
		for (int i = 0; i < s; i++) {
			int xxx = wq.front().first.first, yyy = wq.front().first.second;
			int cnt = q.front().second;
			bfsw(xxx, yyy, cnt);
			wq.pop();
		}
		arr[f.first][f.second] = '.';
		if (!ss) break;
		for (int i = 0; i < ss; i++) {
			int xx = q.front().first, yy = q.front().second;
			bfs(xx, yy);
			q.pop();
			if (flag) {
				printf("%d", ans);
				return 0;
			}
		}
	}
	printf("KAKTUS");
}