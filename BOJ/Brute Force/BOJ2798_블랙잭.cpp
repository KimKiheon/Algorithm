#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[105], check[105], ans = 2e9;
void go(int n, int idx, int key, int cnt, int sum) {
	if (cnt == 3) {
		if (sum > key)return;
		ans = min(ans, key - sum);
		return;
	}
	for (int i = idx + 1; i < n; i++) {
		if (!check[i]) {
			check[i] = 1;
			sum += arr[i];
			go(n, i, key, cnt+1,sum);
			sum -= arr[i];
			check[i] = 0;
		}
	}
}
int main() {
	int n, num;
	cin >> n >> num;
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++) {
		check[i] = 1;
		go(n, i, num, 1, arr[i]);
		check[i] = 0;
	}
	cout << num-ans << endl;
	return 0;
	
}