#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int check[10];
int main(void) {
	int num, x, x2, i2;
	cin >> num;
	for (int i = 1; i < min(100000, num); i++) {
		int temp = 1;
		memset(check, 0, sizeof(check));
		x = num - i;
		x2 = x;
		i2 = i;
		while (x2) {
			check[x2 % 10]++;
			x2 /= 10;
		}
		while (i2) {
			check[i2 % 10]++;
			i2 /= 10;
		}
		for (int j = 0; j < 10; j++) {
			if (check[j] > 1)temp = 0;
		}
		if (temp) {
			cout << x << " + " << i;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}