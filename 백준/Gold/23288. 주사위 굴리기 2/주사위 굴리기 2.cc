#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int cnt, n, m, k, ans, dir = 0, add[21][21];//동남서북
int arr[21][21], check[21][21];
vector<int>v;
typedef struct Dice {
	int N = 2, S = 5, E = 3, W = 4, U = 1, D = 6;
	int x = 1, y = 1;
}D;
typedef pair<int, int>p;
D dice;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<p>q;
int isValid(int x, int y) {
	return !(x<1 || x>n || y<1 || y>m);
}
void cal(int now, int x, int y) { //각 칸에서 dfs로 몇을 더해줄지 계산
	check[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!isValid(nx, ny) || arr[nx][ny] != now || check[nx][ny])continue;
		cnt++;
		q.push({ nx,ny });
		cal(now, nx, ny);
	}
}
void rotate() { //시계방향 방향전환
	++dir;
	dir %= 4;
}
void rRotate() { //반시계방향 전환
	--dir;
	if (dir < 0)dir = 3;
}
void move() {
	if (dir == 0) { // 동쪽이동
		int tmp = dice.U;
		dice.U = dice.W, dice.W = dice.D, dice.D = dice.E, dice.E = tmp;
	}
	else if (dir == 1) { // 남쪽이동
		int tmp = dice.U;
		dice.U = dice.N, dice.N = dice.D, dice.D = dice.S, dice.S = tmp;
	}
	else if (dir == 2) { // 서쪽이동
		int tmp = dice.U;
		dice.U = dice.E, dice.E = dice.D, dice.D = dice.W, dice.W = tmp;
	}
	else if (dir == 3) { // 북쪽이동
		int tmp = dice.U;
		dice.U = dice.S, dice.S = dice.D, dice.D = dice.N, dice.N = tmp;
	}
}
void input() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
}
p reverseDir(int x, int y) { //벽에 부딫히면 방향 전환
	dir = (dir + 2) % 4;
	return { x + 2 * dx[dir], y + 2 * dy[dir] };
}
void go() {
	while (k--) {
		int nx = dice.x + dx[dir], ny = dice.y + dy[dir]; //nx, ny
		if (!isValid(nx, ny)) { //범위 벗어나면
			p tmp = reverseDir(nx, ny);
			nx = tmp.first, ny = tmp.second; //방향 전환
		}
		move(); //주사위 이동
		ans += add[nx][ny];
		if (dice.D > arr[nx][ny]) rotate(); //시계방향
		else if (dice.D < arr[nx][ny]) rRotate();//반시계방향
		dice.x = nx, dice.y = ny;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	input();
	for (int i = 1; i <= n; i++) { //각 칸별 도착하면 몇 더할 수 있는지 구하기
		for (int j = 1; j <= m; j++) {
			cnt = 1;
			if (!check[i][j]) { //cal(arr[i][j], i, j);
				q.push({ i,j });
				cal(arr[i][j], i, j);
			}
			while (!q.empty()) {
				p now = q.front();
				q.pop();
				add[now.first][now.second] = cnt * arr[i][j];
			}
		}
	}
	go();
	cout << ans << "\n";
	return 0;
}