#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<deque>
using namespace std;
typedef struct Tree {
	int x, y;
}T;
vector<int> v[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
int n, m, K, arr[11][11], add[11][11];
deque<T> spread;
int isValid(int x, int y) {
	return !(x<1 || x>n || y<1 || y>n);
}
int canMod(int x) {
	return (x % 5) == 0;
}
void input() {
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> add[i][j];
			arr[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		v[x][y].push_back(age);
	}
}
void spring() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sort(v[i][j].begin(), v[i][j].end());
			int deadSum = 0;
			vector<int> live;
			for (int k = 0; k < v[i][j].size(); k++) {
				if (arr[i][j] < v[i][j][k]) {
					deadSum += v[i][j][k] / 2;
					continue;
				}
				live.push_back(v[i][j][k] + 1);
				if (canMod(v[i][j][k] + 1)) {
					spread.push_back({ i,j });
				}
				arr[i][j] -= v[i][j][k];
			}
			arr[i][j] += deadSum;
			v[i][j] = live;
		}
	}
}
void autumn() {
	while (!spread.empty()) {
		T now = spread.back();
		spread.pop_back();
		for (int i = 0; i < 8; i++) {
			int nx = now.x + dx[i], ny = now.y + dy[i];
			if (!isValid(nx, ny))continue;
			v[nx][ny].push_back(1);
		}
	}
	
}
void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += add[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	input();
	while (K--) {
		spring();
		autumn();
		winter();
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += v[i][j].size();
		}
	}
	cout << ans << "\n";
	return 0;
}