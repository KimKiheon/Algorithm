#include<iostream>
using namespace std;
int arr[10], num, depth;
void go(int idx, int n, int d) {
	if (idx == d) {
		for (int i = 0; i < d; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[idx] = i;
		go(idx + 1, n, d);
		arr[idx] = 0;
	}
	return;
}
int main() {
	cin >> num >> depth;
	go(0, num, depth);
	return 0;
}