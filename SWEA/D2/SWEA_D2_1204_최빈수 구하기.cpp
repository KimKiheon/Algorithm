#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(int argc, char** argv){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int check[101];
		int testNum, maxi = 0;
		cin >> testNum;
		memset(check, 0, sizeof(check));
		int ans = 0;
		for (int i = 0; i < 1000; i++) {
			int num;
			cin >> num;
			check[num]++;
		}
		for (int i = 1; i <= 100; i++) {
			if (maxi <= check[i]) {
				maxi = check[i];
				ans = i;
			}
		}
		cout << "#" << testNum << " " << ans << "\n";
	}
	return 0;
}