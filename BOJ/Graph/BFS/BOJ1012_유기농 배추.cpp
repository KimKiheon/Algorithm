#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int arr[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int > > q;
int n, m, k;
void bfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 0) continue;
			q.push({ nx, ny });
			arr[nx][ny] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int answer = 0;
		cin >> n >> m >> k;

		while (k--) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					q.push({ i, j });
					arr[i][j] = 0;
					bfs();
					answer++;
				}
			}
		}

		cout << answer << "\n";
	}
	return 0;
}