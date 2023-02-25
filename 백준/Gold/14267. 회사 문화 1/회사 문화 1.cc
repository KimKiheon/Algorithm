#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int>>v;
int ans[100005];
int score[1000005];
int n, m, a, b;
void dfs(int now, int score) {
	ans[now] += score;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		dfs(next, score);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	v.resize(n+1);
	cin >> a;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		v[a].push_back(i);
	}
	while (m--) {
		cin >> a >> b;
		score[a] += b;
	}
	for (int i = 2; i <= n; i++)if (score[i]) dfs(i, score[i]);
	for (int i = 1; i <= n; i++)cout << ans[i] << " ";
	return 0;
}