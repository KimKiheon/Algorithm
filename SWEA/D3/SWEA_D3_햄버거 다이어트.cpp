#include<iostream>
#include<algorithm>
using namespace std;
int maxi, kcal, n;
int arr[20][2];
void go(int cnt, int sumKcal, int sumScore, int idx) {
	if (sumKcal > kcal)return;
	if (idx == n) {
		maxi = max(maxi, sumScore);
		return;
	}
	go(cnt + 1, sumKcal + arr[idx][1], sumScore + arr[idx][0], idx + 1);
	go(cnt, sumKcal, sumScore, idx + 1);
}
int main() {
	int T, tc = 0;
	cin >> T;
	while (tc++ <= T) {
		maxi = 0;
		cin >> n >> kcal;
		for (int i = 0; i < n; i++) {
			cin >> arr[i][0] >> arr[i][1];
		}
		go(0, 0, 0, 0);
		cout << '#' << tc << ' ' << maxi << "\n";
	}
	return 0;
}