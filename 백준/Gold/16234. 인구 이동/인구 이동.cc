#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int, int>p;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int n, mini, maxi, ans, sum;
int arr[50][50], check[50][50];
bool flag;
queue<p>q;
vector<vector<p>>posv;
vector<int>sumv;
void input() {
	cin >> n >> mini >> maxi;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> arr[i][j];
}
bool canMove(int a, int b) {
	return mini <= abs(a - b) && abs(a - b) <= maxi;
}
void bfs(int tmp,int s) {
	int count = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1||check[nx][ny]|| !canMove(arr[x][y], arr[nx][ny]))continue;//범위값 초과 혹은 방문했다면 혹은 차이가 min~maxi값이 아니라면
			check[nx][ny] = tmp;
			q.push({ nx,ny });
			s += arr[nx][ny];
			posv[tmp - 1].push_back({ nx,ny });
		}
	}
	sumv.push_back(s);
}
int search() {
	int connectionCnt = 0;
	posv.clear();
	sumv.clear();
	posv.resize(n * n);
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j])continue;
			q.push({ i,j });
			check[i][j] = ++connectionCnt;
			bfs(connectionCnt,arr[i][j]);
			posv[connectionCnt-1].push_back({i,j});
		}
	}
	return connectionCnt;
}
int move(int conn) {
	if (conn == n * n)return 0;
	int cnt = 0;
	for (int i = 0; i < conn; i++) {
		int s = posv[i].size();
		int tmp = sumv[i] / s;
		for (int j = 0; j < s; j++) {
			int x = posv[i][j].first, y = posv[i][j].second;
			if (arr[x][y] == tmp) {
				cnt++;
			}
			arr[x][y] = tmp;
		}
	}
	ans++;
	if (cnt == n * n) return 0;
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	input();
	while (move(search())) {
	}
	cout << ans << "\n";
	return 0;
}