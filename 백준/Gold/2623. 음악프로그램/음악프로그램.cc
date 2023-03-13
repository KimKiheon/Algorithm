#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>>v;
queue<int>q;
int n, m;
int indegree[1005];
int check[1005];
vector<int>ans;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		vector<int>tmp;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			tmp.push_back(b);
		}
		for (int j = 0; j < a - 1; j++) {
			v[tmp[j]].push_back(tmp[j + 1]);
			indegree[tmp[j + 1]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!indegree[i])q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		check[now] = 1;
		ans.push_back(now);
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (check[next])continue;
			if (!--indegree[next]) {
				q.push(next);
			}
		}
	}
	if (ans.size() != n) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;

}