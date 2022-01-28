#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n, sum = 0, cnt = 0;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cnt = sum= v[0];
	for (int i = 1; i < n; i++) {
		cnt += v[i];
		sum += cnt;
	}
	cout << sum << "\n";
	return 0;
}