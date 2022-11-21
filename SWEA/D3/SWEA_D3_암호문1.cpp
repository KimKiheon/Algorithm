#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int T = 10;;
	for (int tc = 1; tc < T; tc++) {
		int arr[20];
		int n, command;
		cin >> n;
		for (int i = 0; i < n; i++)cin >> arr[i];
		cin >> command;
		for (int i = 0; i < command; i++) {
			char a;
			cin >> a;
			int from, to;
			cin >> from >> to;
			for (int j = from; j < from + to; j++) {
				cin >> arr[j];
			}
		}
		cout << "#" << tc << " ";
		for (int i = 0; i < 10; i++)cout << arr[i] << " ";
		cout << "\n";
	}
	return 0;
}