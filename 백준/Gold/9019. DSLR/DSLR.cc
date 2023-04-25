#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
int t, n, m;
string ans;
char arr[4] = { 'D','S','L','R' };
int check[10005];
typedef pair<int, string>p;
void bfs() {
	queue<p>q;
	q.push({ n, "" });
	check[n] = 1;
	while (!q.empty()) {
		int now = q.front().first;
		ans = q.front().second;
		q.pop();
		if (now == m) return;
		for (int i = 0; i < 4; i++) {
			int next;
			if (i == 0) next = (now * 2) % 10000;
			else if (i == 1) next = (now == 0) ? 9999 : now - 1;
			else if (i == 2) next = (now % 1000) * 10 + now / 1000;
			else if (i == 3) next = (now % 10) * 1000 + now / 10;
			if (check[next])continue;
			check[next] = 1;
			q.push({ next,ans + arr[i] });
		}
	}
		
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		ans = "";
		memset(check, 0, sizeof(check));
		bfs();
		cout << ans << "\n";
	}
	return 0;
}