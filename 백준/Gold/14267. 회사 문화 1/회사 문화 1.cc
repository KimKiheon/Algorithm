#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int>>v;
int ans[100005];
int score[1000005];
int n, m, a, b;
//solve1. 입력받으면서 dfs를 돌리니 시간초과
//solve2. 미리 칭찬점수를 다 입력받고 모든 회사원을 dfs 돌리니 또 시간초과
//solve3. 미리 입력받고 칭찬점수가 있는 회사원만 dfs돌리니 통과


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
	for (int i = 2; i <= n; i++) { //Parent - Child 연결
		cin >> a;
		v[a].push_back(i);
	}
	while (m--) { //칭찬점수 입력
		cin >> a >> b;
		score[a] += b;
	}
	for (int i = 2; i <= n; i++) {
		if (score[i]) { //칭찬점수가 0점이 아닌 경우에만 dfs
			dfs(i, score[i]);
		}
	}
	for (int i = 1; i <= n; i++)cout << ans[i] << " ";
	return 0;
}