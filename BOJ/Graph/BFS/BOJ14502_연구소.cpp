#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
int n, m, ans;
int map[9][9], map2[9][9];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>>pv;
queue<pair<int, int>>pq;
void go(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map2[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < pv.size(); i++) {
			pq.push(pv[i]);
		}

		while (!pq.empty()) {
			int x = pq.front().first;
			int y = pq.front().second;
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (map[nx][ny] == 0 && nx >= 0 && nx < n && ny >= 0 && ny < m) {
					map[nx][ny] = 2;
					pq.push({ nx, ny });
				}
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!map[i][j])count++;
			}
		}
		ans = max(ans, count);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = map2[i][j];
			}
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) {
				map[i][j] = 1;
				go(cnt + 1);
				map[i][j] = 0;
			}
		}
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				pv.push_back({ i,j });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) {
				map[i][j] = 1;
				go(1);
				map[i][j] = 0;
			}
		}
	}
	cout << ans;
}