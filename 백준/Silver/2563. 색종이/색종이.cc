#include<iostream>
using namespace std;
int check[105][105];
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				if (!check[j][k]) {
					check[j][k] = 1;
					ans++;
				}
			}
		}
	}
	cout << ans;
}