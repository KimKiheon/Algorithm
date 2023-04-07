#include<iostream>
using namespace std;
long long fibo[2000005], n;
long long k;
int getCount() {
	int cnt = 3;
	while (1) {
		fibo[cnt] = fibo[cnt - 1] + fibo[cnt - 2];
		if (fibo[cnt] > k) break;
		cnt++;
	}
	return cnt;
}
int main() {
	cin >> k;
	fibo[0] = fibo[1] = 1;
	fibo[2] = 2;
	int cnt;
	if (k == 1) {
		cout << 1;
		return 0;
	}
	else if (k == 2) {
		cout << 10;
		return 0;
	}
	cnt = getCount() - 1;
	while (cnt) {
		if (fibo[cnt] <= k) {
			cout << 1;
			k -= fibo[cnt--];
		}
		else {
			cout << 0;
			cnt--;
		}
	}
}