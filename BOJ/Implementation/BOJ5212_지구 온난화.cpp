#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int n, m;
char arr[15][15] = { "" };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			if (arr[i][j] == 'X') {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (arr[nx][ny] == '.' || nx < 0 || n <= nx || ny < 0 || m <= ny) cnt++;
					if (cnt > 2)arr[i][j] = 'a';
				}
			}
		}
	}
	int sx = 105, ex = -1, sy = 105, ey = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'a')arr[i][j] = '.';
			else if (arr[i][j] == 'X') {
				sx = min(sx, j);
				ex = max(ex, j);
				sy = min(sy, i);
				ey = max(ey, i);
			}
		}
	}
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}