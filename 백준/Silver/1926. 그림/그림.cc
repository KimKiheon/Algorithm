#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
int n, m, ans;
int arr[500][500];
int check[500][500];
typedef pair<int, int>p;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
queue<p>q;
int bfs() {
	int cnt = 1;
	while (!q.empty()) {
		p now = q.front();
		int x = now.first, y = now.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || check[nx][ny] || !arr[nx][ny])continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
			cnt++;
		}
	}
	return cnt;
}
int main() {
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] && !check[i][j]) {
				cnt++;
				q.push({ i,j });
				check[i][j] = 1;
				ans = max(ans, bfs());
			}
		}
	}
	if (!cnt)cout << 0 << "\n" << 0 << "\n";
	else cout << cnt << "\n" << ans << "\n";
	return 0;
}