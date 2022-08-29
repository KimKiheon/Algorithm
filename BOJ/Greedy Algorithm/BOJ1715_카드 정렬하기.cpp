#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n, ans;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		pq.push(a);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int tmp = pq.top();
		pq.pop();
		tmp += pq.top();
		pq.pop();

		ans += tmp;
		pq.push(tmp);
	}
	cout << ans;
	return 0;
}