#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int>p;
int arr[8001];
int maxnum, maxcnt;
double sum, avg;
vector<int>v;
vector<int>tmp;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a + 4000]++;
		sum += a;
		v.push_back(a);
		maxcnt = max(maxcnt, arr[a + 4000]);
	}
	avg = sum / (double)n;
	avg = floor(avg + 0.5);
	sort(v.begin(), v.end());
	for (int i = 0; i < 8001; i++) {
		if (maxcnt == arr[i])tmp.push_back(i);
	}

	cout << avg << "\n";
	cout << v[n / 2] << "\n";
	if (tmp.size() > 1)	cout << tmp[1] - 4000 << "\n";
	else cout << tmp[0] - 4000 << "\n";
	cout << v[n - 1] - v[0] << "\n";

	return 0;
}
