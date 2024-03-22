
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
struct pos {
	int x, y;
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
bool visitRed[4][4];
bool visitBlue[4][4];
bool redEnd, blueEnd;

bool canMove(vector<vector<int>> maze, pos red, pos nextRed, pos blue, pos nextBlue) {
	//범위 이탈
	if (nextRed.x < 0 || nextRed.x > n-1 || nextRed.y < 0 || nextRed.y >m - 1 || nextBlue.x < 0 || nextBlue.x > n-1 || nextBlue.y < 0 || nextBlue.y > m - 1) return false;
	//next가 벽
	if (maze[nextRed.x][nextRed.y] == 5 || maze[nextBlue.x][nextBlue.y] == 5) return false;
	//둘이 위치를 스위칭
	if ((red.x == nextBlue.x && red.y == nextBlue.y) && (blue.x == nextRed.x && blue.y == nextRed.y)) return false;
	//next가 동일한 위치
	if (nextRed.x == nextBlue.x && nextRed.y == nextBlue.y) return false;
	//중복방문
	if ((!redEnd && visitRed[nextRed.x][nextRed.y]) 
		|| (!blueEnd && visitBlue[nextBlue.x][nextBlue.y])) return false;

	return true;
}
pos getNext(int x, int y, int dir) {
	return { x + dx[dir], y + dy[dir] };
}
int dfs(vector<vector<int>>maze, pos red, pos blue, int cnt) {
	if (redEnd && blueEnd) return cnt;
	int ans = 2e9;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			pos nextRed = redEnd ? red : getNext(red.x, red.y, i);
			pos nextBlue = blueEnd ? blue : getNext(blue.x, blue.y, j);

			if (!canMove(maze, red, nextRed, blue, nextBlue)) continue;

			visitRed[nextRed.x][nextRed.y] = true;
			visitBlue[nextBlue.x][nextBlue.y] = true;
			if (maze[nextRed.x][nextRed.y] == 3) redEnd = true;
			if (maze[nextBlue.x][nextBlue.y] == 4) blueEnd = true;

			ans = min(ans, dfs(maze, nextRed, nextBlue, cnt + 1));

			visitRed[nextRed.x][nextRed.y] = false;
			visitBlue[nextBlue.x][nextBlue.y] = false;
			blueEnd = false;
			redEnd = false;
		}
	}
	return ans;
}

int solution(vector<vector<int>> maze) {
	int answer = 0;
	n = maze.size();
	m = maze[0].size();
	cout << n << " " << m << "\n";
	pos red, blue;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 1) red = { i,j };
			else if (maze[i][j] == 2) blue = { i,j };

		}
	}

	visitRed[red.x][red.y] = true;
	visitBlue[blue.x][blue.y] = true;
	answer = dfs(maze, red, blue, 0);
	return answer == 2e9 ? 0 : answer;
}
