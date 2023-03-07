#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
int t, n;
int arr[100][100];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 }, dist[100][100];
typedef pair<int, pair<int, int>>p;
priority_queue<p, vector<p>, greater<p>> pq;
p start;
void go() {
	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();
		int x = now.second.first, y = now.second.second, cost = arr[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1)continue;
			if (dist[nx][ny] > dist[x][y] + cost) {
				dist[nx][ny] = dist[x][y] + cost;
				pq.push({ dist[nx][ny],{nx,ny} });
			}
			
		}
	}
}
int main() {
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &arr[i][j]);
				dist[i][j] = 2e9;
			}
		}
		start = { 0,{0,0} };
		dist[0][0] = 0;
		pq.push(start);
		go();
		printf("#%d %d\n",tc, dist[n - 1][n - 1]);
	}
}