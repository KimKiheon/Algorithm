#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef pair<int, int>p;
int n, m, cnt, ans, temp,
dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool check;
p arr[305][305];
int visited[305][305];
void melting() {
	for (int i = 1; i < n - 1; i++) {
		if (check)break;
		for (int j = 1; j < m - 1; j++) {
			if (arr[i][j].first) {
				cnt = 0;
				for (int k = 0; k < 4; k++)
					if (!arr[i + dx[k]][j + dy[k]].first)cnt++;
				arr[i][j].second = cnt;
			}
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			arr[i][j].first -= arr[i][j].second;
			arr[i][j].first = max(arr[i][j].first, 0);
		}
	}
}
void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!visited[nx][ny] && arr[nx][ny].first && 1 <= nx && nx < n - 1 && 1 <= ny && ny < m - 1)
			dfs(nx, ny);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%d", &arr[i][j].first);
	while (1) {
		memset(visited, 0, sizeof(visited));
		temp = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (!visited[i][j] && arr[i][j].first) {
					temp++;
					if (temp > 1) {
						check = true;
						break;
					}
					dfs(i, j);
				}
			}
		}
		if (check) break;
		if (!temp) {
			ans = 0;
			break;
		}
		melting();
		ans++;
	}
	printf("%d", ans);
}