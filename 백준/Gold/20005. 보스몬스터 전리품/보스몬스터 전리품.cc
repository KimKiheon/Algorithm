#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<unordered_map>
using namespace std;

typedef pair<int, int> p;
int sx, sy;
char arr[1005][1005];
unordered_map<char, int>player;
int hp, n, m, num;
int visited[1005][1005];
int sum, cnt;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
vector<p>v;
bool isValid(int x, int y) {
	return !(x<0 || x>n - 1 || y<0 || y>m - 1);
}
void bfs() {
	queue<p>q;
	q.push({ sx,sy });
	while (!q.empty()) {
		p now = q.front();
		q.pop();
		int x = now.first, y = now.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!isValid(nx, ny) || arr[nx][ny] == 'X' || visited[nx][ny])continue;
			q.push({ nx,ny });
			visited[nx][ny] = visited[x][y] + 1;
			if (!('a' <= arr[nx][ny] && arr[nx][ny] <= 'z')) continue;
			v.push_back({ visited[nx][ny], player.find(arr[nx][ny]) -> second });
		}
	}
}
void attack() {
	int sec = v[0].first;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int gap = v[i].first - sec;
		sec = v[i].first;
		int tmp = 0;
		hp -= sum * gap;
		if (hp + sum <= 0) return;
		while ((i + tmp < v.size()) && v[i].first == v[i + tmp].first) {
			hp -= v[i + tmp].second;
			sum += v[i + tmp].second;
			cnt++;
			tmp++;
		}
		i += tmp-1;
		if (hp < 0) return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 'B') continue;
			sx = i, sy = j;
		}
	}
	for (int i = 0; i < num; i++) {
		char a;
		int b;
		cin >> a >> b;
		player.insert({ a, b });
	}
	cin >> hp;
	bfs();
	sort(v.begin(), v.end());
	attack();
	cout << cnt;
	return 0;
}