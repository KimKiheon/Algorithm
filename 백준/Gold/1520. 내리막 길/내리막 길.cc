#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[505][505], dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int n, m;
int dp[505][505] = { -1, };
int isValid(int x, int y) {
	return !(x<0 || x>n - 1 || y<0 || y>m - 1);
}
int go(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		return 1;
	}
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!isValid(nx, ny) || arr[x][y] <= arr[nx][ny])continue;
		dp[x][y] += go(nx, ny);
	}
	return dp[x][y];
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << go(0, 0) << "\n";
}