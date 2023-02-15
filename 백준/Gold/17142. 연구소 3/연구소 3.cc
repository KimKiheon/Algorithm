#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int>p;
int ans = 2e9, dist[50][50], arr[50][50];
vector<p>virus;
int selected[10], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int n, m, blank;
queue<p>q;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 1) virus.push_back({ i,j });
			if (!arr[i][j])blank++;
		}
	}
}
void bfs() {
	int cnt = 0, second = 0;
	while (!q.empty()) {
		p now = q.front();
		q.pop();
		int x = now.first, y = now.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] == 1)continue;
			if (dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + 1;
				if (arr[nx][ny] == 0) {
					cnt++;
					second = dist[nx][ny];
				}
				q.push({ nx,ny });
			}
		}
	}
	if (cnt == blank && ans > second)ans = second;
}
void combination(int idx, int cnt) {
	if (cnt == m) {
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < virus.size(); i++) {
			if (selected[i]) {
				int x = virus[i].first, y = virus[i].second;
				q.push({ x,y });
				dist[x][y] = 0;
			}
		}
		bfs();
		return;
	}
	for (int i = idx; i < virus.size(); i++) {
		if (!selected[i]) {
			selected[i] = 1;
			combination(i + 1, cnt + 1);
			selected[i] = 0;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	input();
	combination(0, 0);
	if (ans == 2e9) {
		cout << -1 << "\n";
		return 0;
	}
	cout << ans << "\n";
	return 0;
}