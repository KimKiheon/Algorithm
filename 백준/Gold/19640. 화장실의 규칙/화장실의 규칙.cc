#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
	int day;
	int toilet;
	int line;
	bool flag;
};

int arr[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	vector<vector<Node>> v;
	vector<int> count;
	auto compare = [](const Node& n1, const Node& n2) {
		if (n1.day != n2.day) return n1.day < n2.day;
		if (n1.toilet != n2.toilet) return n1.toilet < n2.toilet;
		if (n1.line != n2.line) return n1.line > n2.line;
	};
	priority_queue<Node, vector<Node>, decltype(compare)>pq(compare);
	int n, m, k;
	cin >> n >> m >> k;
	v.resize(m);
	count.resize(m);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt %= m;
		bool flag = false;
		if (i == k) flag = true;
		int d, t;
		cin >> d >> t;
		v[cnt].push_back({ d,t,cnt,flag });
		cnt++;
	}
	for (int i = 0; i < min(n,(int)v.size()); i++) pq.push(v[i][0]);
	for (int i = 0; i < n; i++) {
		Node node = pq.top();
		pq.pop();
		if (node.flag) {
			cout << i;
			return 0;
		}
		count[node.line]++;
		if (count[node.line] >= v[node.line].size()) continue;
		pq.push(v[node.line][count[node.line]]);
	}
}