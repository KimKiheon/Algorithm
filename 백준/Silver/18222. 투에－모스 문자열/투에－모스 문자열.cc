#include<iostream>
using namespace std;
long long k;
int go(long long x) {
	if (x == 0)return 0;
	if (x == 1)return 1;
	if (x % 2 == 0)return	go(x / 2);
	return 1 - go(x / 2);
}
int main() {
	cin >> k;
	cout << go(k - 1) << "\n";
	return 0;
}