#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000

int n;
int arr[MAXN];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	if (arr[0] > 0) {
		cout << -1 << '\n';
		return 0;
	}
	arr[0] = 0;
	int t = -1, req = 0, pos = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (t != -1 && arr[i] != -1 && arr[i] != t) {
			cout << -1 << '\n';
			return 0;
		}
		if (t == -1)	t = arr[i];
		if (arr[i] == -1)arr[i] = t;
		if (arr[i] == 0)	req++;
		if (arr[i] == -1)pos++;
		if (t > -1)t--;
	}
	cout << req << ' ' << req + pos << '\n';
	return 0;
}