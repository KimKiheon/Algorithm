#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
typedef pair<int, int>p;
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };
int n, m, check[505][505], cnt;
p arr[505][505];
vector<p>v;
queue<p>q;
vector<int>ans;
p k;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> k.first >> k.second;
	ans.resize(m);
	k.first--, k.second--;
	check[k.first][k.second] = 1;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a - 1][b - 1] = { 1,cnt++ };
	}
	q.push({ k });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || check[nx][ny])continue;
			if (arr[nx][ny].first == 1)ans[arr[nx][ny].second] = check[x][y];
			check[nx][ny] = check[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	for (int i = 0; i < m; i++)cout << ans[i] << " ";
	return 0;
}