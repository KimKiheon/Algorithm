#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main() {
	queue<int>q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)q.push(i);
	if (n == 1) {
		cout << 1 << "\n";
		return 0;
	}
	while (1) {
		q.pop();
		int tmp = q.front();
		if (q.size() == 1) {
			cout << tmp << "\n";
			break;
		}
		q.pop();
		q.push(tmp);
	}
	return 0;
}