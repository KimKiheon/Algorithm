#include <iostream>
using namespace std;
long long a, b, c, k;
long long go(long long n) {
	if (n == 0) return 1;
	if (n == 1) return a % c;

	k = go(n / 2) % c;
	if (n % 2 == 0) return k * k % c;
	return k * k % c * a % c;
}

int main(void) {
	cin >> a >> b >> c;
	cout << go(b) << "\n";

	return 0;
}