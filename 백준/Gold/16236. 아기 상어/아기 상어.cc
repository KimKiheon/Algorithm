#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
struct Fish {
	int s, x, y;
};
typedef pair<int, int>p;
p now;
int n, ans, sharkSize = 2, expe;
int arr[21][21], check[21][21];
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
vector<Fish>canEat;
queue<p>q;
bool compare(const Fish& f1, const Fish& f2) {
	if (f1.s == f2.s) {
		if (f1.x == f2.x) return f1.y < f2.y;
		return f1.x < f2.x;
	}
	return f1.s < f2.s;
}
bool inValid(int x, int y) {
	return !(x<0 || x>n - 1 || y<0 || y>n - 1);
}
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				now = { i,j };
				arr[i][j] = 0;
			}
		}
	}
	expe = 2;
}
int bfs() {
	q.push(now);
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!inValid(nx,ny)|| arr[nx][ny] > sharkSize||check[nx][ny])continue; 
			check[nx][ny] = check[x][y] + 1;
			q.push({ nx,ny });
			if (arr[nx][ny] && arr[nx][ny] < sharkSize) {
				canEat.push_back({ check[nx][ny],nx,ny });
			}
		}
	}
	return canEat.size();
}
void eat(Fish target) {
	ans += check[target.x][target.y];
	arr[target.x][target.y] = 0;
	now = { target.x,target.y };
	expe--;
	if (!expe) {
		expe = ++sharkSize;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	input();
	while (bfs()) {
		sort(canEat.begin(), canEat.end(), compare);
		Fish target = canEat[0];
		eat(target);
		memset(check, 0, sizeof(check));
		canEat.clear();
	}
	cout << ans << "\n";
}