#include<iostream>
using namespace std;
int arr[10], num, depth;
void go(int idx, int n, int d, int start) {
	if (idx == d) {
		for (int i = 0; i < d; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i <= n; i++) {
		arr[idx] = i;
		go(idx + 1, n, d, i + 1);
		arr[idx] = 0;
	}
}
int main() {
	cin >> num >> depth;
	go(0, num, depth, 1);
	return 0;
}