#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, a = 0, b = 0, c = 0;
	cin >> n;
	if (n % 10) {
		cout << "-1" << "\n";
		return 0;
	}
	a = n / 300;
	n -= 300 * a;
	b = n / 60;
	n -= 60 * b;
	c = n / 10;
	cout << a << " " << b << " " << c << "\n";
	return 0;
}