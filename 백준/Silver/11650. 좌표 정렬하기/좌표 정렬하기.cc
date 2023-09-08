#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int>p;
int main() {
	p arr[100005];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a,b };
	}
	sort(arr, arr + n);
	for (int i = 0; i < n;i++) {
		p a = arr[i];
		cout << a.first << " " << a.second << "\n";
	}
	return 0;
}