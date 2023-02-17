#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int, int>p;
int ans = 2e9, arr[50][50];
vector<p>chicken,home;
vector<int>dist;
int selected[13];
int n, m, blank;
vector<p>q;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) chicken.push_back({ i,j });
			if (arr[i][j] == 1) home.push_back({ i,j });
		}
	}
	dist.resize(home.size());
}
void go() {
	int sum = 0;
	for(int i=0;i<home.size();i++) {
		int dist = 2e9;
		for (int j = 0; j < q.size(); j++) {
			p now = q[j];
			dist = min(dist, abs(now.first - home[i].first) + abs(now.second - home[i].second));
		}
		sum += dist;
	}
	ans = min(ans, sum);

}
void combination(int idx, int cnt) {
	if (cnt == m) {
		q.clear();
		for (int i = 0; i < chicken.size(); i++) {
			if (selected[i]) {
				int x = chicken[i].first, y = chicken[i].second;
				q.push_back({ x,y });
			}
		}
		go();
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (!selected[i]) {
			selected[i] = 1;
			combination(i + 1, cnt + 1);
			selected[i] = 0;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	input();
	combination(0, 0); //조합
	cout << ans << "\n";
	return 0;
}