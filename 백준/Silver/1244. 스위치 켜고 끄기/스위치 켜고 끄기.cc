#include<iostream>
using namespace std;
bool arr[100];
int switchSize, n, gender, number;
int main() {
	cin >> switchSize;
	for (int i = 0; i < switchSize; i++) {
		int a;
		cin >> a;
		if (a)arr[i] = 1;
		else arr[i] = 0;
	}
	cin >> n;
	while (n--) {
		cin >> gender >> number;
		if (gender == 1) {

			for (int i = number - 1; i < switchSize; i += number) {
				arr[i] = !arr[i];
			}
		}
		else {
			number--;
			arr[number] = !arr[number];
			for (int i = 1;; i++) {
				if (number - i < 0 || switchSize <= number + i||
					(arr[number-i]!=arr[number+i]))break;
				arr[number - i] = !arr[number - i];
				arr[number + i] = !arr[number + i];
				
			}
		}
	}
	for (int i = 1; i <= switchSize; i++) {
		if (arr[i-1])cout << 1 << " ";
		else cout << 0 << " ";
		if (i % 20 == 0)cout << "\n";

		

	}
	return 0;
}