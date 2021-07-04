#include<iostream>
using namespace std;
int main() {
	int n, ans = 0, i = 1;
	cin >> n;
	if (n == 4)cout << -1 << endl;
	else if (n % 5 == 0) cout << n / 5;
	else {
		while (n > 0) {
			if ((n - 3) % 5 == 0) {
				cout << n / 5 + i;
				return 0;
			}
			n -= 3;
			i++;
		}
		cout << -1;
	}
}