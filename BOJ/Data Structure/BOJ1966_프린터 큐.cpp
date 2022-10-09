#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>p;
int main() {
	int T, n, key, input, ans;
	cin >> T;
	while (T--) {
		queue<p>q;
		vector<int>v;
		ans = 0;
		cin >> n >> key;
		for (int i = 0; i < n; i++) {
			cin >> input;
			if (key == i) q.push({ input,1 });
			else q.push({ input,0 });
			v.push_back(input);
		}
		sort(v.begin(), v.end());
		p tmp = q.front();
		while (1) {
			if (tmp.first == v[v.size() - 1]&&tmp.second) {
				break;
			}
			else if (tmp.first == v[v.size() - 1] && !tmp.second) {
				q.pop();
				v.pop_back();
				ans++;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		cout << ans+1 << "\n";
	}
	return 0;
}