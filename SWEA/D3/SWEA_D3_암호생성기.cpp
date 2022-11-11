#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int main() {
	int tc = 10;
	while (tc--) {
		int T, num, flag = 1;
		cin >> T;
		deque<int>dq;
		for (int i = 0; i < 8; i++) {
			cin >> num;
			dq.push_back(num);
		}
		while (flag) {
			for (int i = 1; i <= 5; i++) {
				int front = dq.front();
				dq.pop_front();
				if (front - i <= 0) {
					flag--;
					dq.push_back(0);
					break;
				}
				dq.push_back(front - i);
			}
		}
		cout << "#" << T;
		for (int i = 0; i < 8; i++) {
			cout << " " << dq.front();
			dq.pop_front();
		}
		cout << "\n";
	}
	return 0;
}