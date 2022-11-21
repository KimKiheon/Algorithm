#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int, int>p;
char arr[105][105];
char arr2[105][105];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int check[105][105];
int n;
int ans;
queue<p> q;
void bfs(char c, char map[][105]) {
	
	while (!q.empty()) {
		p now = q.front();
		int x = now.first, y = now.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] == c && !check[nx][ny]) {
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}


}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &arr[i][j]);
			arr2[i][j] = arr[i][j];
			if (arr2[i][j] == 'R')arr2[i][j] = 'G';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				check[i][j] = 1;
				q.push({ i,j });
				bfs(arr[i][j],arr);
				ans++;
			}
		}
	}
	cout << ans << " ";
	memset(check, 0, sizeof(check));
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				q.push({ i,j });
				bfs(arr2[i][j], arr2);
				ans++;
			}
		}
	}
	cout << ans<<"\n";
	return 0;
}