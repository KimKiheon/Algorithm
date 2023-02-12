#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int>p;
int n, dist, weight, ans = 0, sum, cnt, tmp;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> dist >> weight;
	vector<int>v(n);
	deque<p> onBridge;
	for (int i = 0; i < n; i++)cin >> v[i];
	while (1) {
		ans++;
		for (int i = 0; i < onBridge.size(); i++) onBridge[i].second--;
		if (!onBridge.empty() && !onBridge.front().second) {
			sum -= onBridge.front().first;
			onBridge.pop_front();
		}
		if (cnt > n - 1 && onBridge.empty())break;
		if (cnt < n&& sum + v[cnt] <= weight) {
			onBridge.push_back({ v[cnt++],dist });
			sum += onBridge.back().first;
		}
	}
	cout << ans << "\n";
	return 0;
}