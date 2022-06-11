#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
typedef pair<int, int>p;
queue<p> q;
int arr[105][105], visited[105][105], dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int n, cnt = 1, maxi, ans[105][105];
void dfs(int x, int y) {
	visited[x][y] = 1, arr[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!visited[nx][ny] && arr[nx][ny] && 0 <= nx && nx < n && 0 <= ny && ny < n)dfs(nx, ny);
	}
}
void bfs(int x, int y, int num) {
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		p now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (arr[nx][ny] && arr[nx][ny] != num && 0 <= nx && nx < n && 0 <= ny && ny < n) {
				cnt = min(cnt, ans[now.first][now.second]);
				while (!q.empty())q.pop();
				return;
			}
			if (!visited[nx][ny] && !arr[nx][ny] && 0 <= nx && nx < n && 0 <= ny && ny < n) {
				visited[nx][ny] = 1;
				ans[nx][ny] = ans[now.first][now.second] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	cnt = 987654321;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k], ny = j + dy[k];
			if (!visited[i][j] && arr[i][j] && !arr[nx][ny] && 0 <= nx && nx < n && 0 <= ny && ny < n) {
				bfs(i, j, arr[i][j]);
				memset(ans, 0, sizeof(ans));
				memset(visited, 0, sizeof(visited));
			}
		}
	cout << cnt << "\n";
	return 0;
}