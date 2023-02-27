#include <iostream>
using namespace std;
int n, m, ans, cnt;
char arr[1001][1001];
int visited[1001][1001];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			int x = i, y = j;
			while (!visited[x][y]) {
				visited[x][y] = cnt;
				char now = arr[x][y];
				if (now == 'S') x++;
				else if (now == 'E') y++;
				else if (now == 'N') x--;
				else if (now == 'W') y--;
			}
			if (visited[x][y] == cnt) {
				ans++;
			}
			cnt++;
		}
	}
	cout << ans;
	return 0;
}