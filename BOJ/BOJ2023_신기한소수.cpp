#include<iostream>
#include<math.h>
using namespace std;
int arr[4] = { 2,3,5,7 };
int n;
bool isPrime(int n) {
	if (n == 1 || n == 0)return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return true;
}
void go(int first, int cnt) {
	if (!cnt)printf("%d\n", first);
	for (int i = 1; i < 10; i += 2) {
		int temp = first * 10 + i;
		if (isPrime(temp))go(temp, cnt - 1);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < 4; i++) {
		go(arr[i], n - 1);
	}
}