#include<iostream>
#include<algorithm>
using namespace std;
int arr[10];
int n;
int main() {
	scanf("%d", &n);
	while (n > 0) {
		arr[n % 10]++;
		n /= 10;
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9)continue;
		ans = max(ans, arr[i]);
	}
	printf("%d", max(ans, (arr[6] + arr[9] + 1) / 2));
	return 0;
}