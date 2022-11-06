#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<functional>
using namespace std;
int main() {
	int tc = 0;
	while (tc++ != 10) {
		priority_queue<int>pq1;
		priority_queue<int, vector<int>, greater<int>>pq2;
		int n;
		cin >> n;
		for (int i = 0; i < 100; i++) {
			int a;
			cin >> a;
			pq1.push(a);
			pq2.push(a);
		}
		for (int i = 0; i < n; i++) {
			int maxi = pq1.top();
			int mini = pq2.top();
			pq1.pop();
			pq2.pop();
			pq1.push(maxi - 1);
			pq2.push(mini + 1);
		}
		cout << "#" << tc << " " << pq1.top() - pq2.top() << "\n";
	}
	return 0;
}
