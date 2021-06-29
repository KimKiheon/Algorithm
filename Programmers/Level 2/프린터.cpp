#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, bool>p;
int solution(vector<int>pro, int location) {
	int cnt = 1;
	deque<p>q;
	for (int i = 0; i < pro.size(); i++)q.push_back({ pro[i],false });
	q[location].second = true;
	sort(pro.begin(), pro.end());
	while (1) {
		if (q.front().first == pro.back()) {
			if (q.front().second)return cnt;
			q.pop_front();
			pro.pop_back();
			cnt++;
			continue;
		}
		p tmp = q.front();
		q.pop_front();
		q.push_back(tmp);
	}
}
/*int main() {
	vector<int>pro;
	int location, n, ans;
	cin >> n;
	pro.resize(n);
	for (int i = 0; i < n; i++)cin >> pro[i];
	cin >> location;
	ans = solution(pro, location);
	cout << ans << endl;
	return 0;
}*/