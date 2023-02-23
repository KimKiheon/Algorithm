#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
int n, m, check[100005], cnt;
queue<int>q;
void find(int now, int next, int sec) {
	if (next < 0 || next>100000)return;
	if (check[next] > check[now] + sec) {
		check[next] = check[now] + sec;
		q.push(next);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	q.push(n);
	for (int i = 0; i < 100005; i++)check[i] = 10000000;
	check[n] = 0;
	while (!q.empty()) {
		int now = q.front(), next[3] = { now -1,now + 1,now * 2 }, sec[3] = { 1,1,0 };
		q.pop();
		if (now == m) {
			cnt++;
			if (cnt > 3)break;
		}
		for (int i = 0; i < 3; i++) {
			if (i && next[i] > 100000)break;
			find(now, next[i], sec[i]);
		}
	}
	cout << check[m] << "\n";
	return 0;
}