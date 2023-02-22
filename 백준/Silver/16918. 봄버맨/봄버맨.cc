#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
int arr[205][205];
int r, c, n;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
typedef pair<int, int>p;
queue<p>q;
void input() {
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			if (str[j] == '.')arr[i][j] = -1;
			else arr[i][j] = 1;
		}
	}
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<0 || nx>r - 1 || ny<0 || ny>c - 1 || !arr[nx][ny])continue;
			arr[nx][ny] = 0;
		}
	}
}
void go() {
	for (int t = 1; t <= n; t++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j]++;
				if (arr[i][j] == 4) {
					arr[i][j] = 0;
					q.push({ i,j });
				}
			}
		}
		if (!q.empty())bfs();
	}
}
void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!arr[i][j])cout << ".";
			else cout << 'O';
		}
		cout << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	input();
	go();
	print();
}