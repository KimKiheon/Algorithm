#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll arr[2000005], ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		double sqr = sqrt(a);
		for (int j = 1; j <= sqr; j++) {
			if (!(a % j)) {
				arr[j]++;
				if (j != sqr)arr[a / j]++;
			}
		}
	}
	for (int i = 1; i <= 2e6; i++) {
		if (arr[i] > 1) {
			ans = max(ans, i * arr[i]);
		}
	}
	cout << ans << "\n";
}