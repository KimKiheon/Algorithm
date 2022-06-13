#include<iostream>
using namespace std;
int a, b;
long long cnt;
void go(long long n) {
	if (n > b)return;
	if (n >= a && n <= b) {
		cnt++;
	}
	go(n * 10 + 4);
	go(n * 10 + 7);
}
int main() {
	cin >> a >> b;
	go(4);
	go(7);
	cout << cnt;
	return 0;
}