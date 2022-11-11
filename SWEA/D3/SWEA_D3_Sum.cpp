#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int arr[100][100];
	for (int tc = 1; tc <= 10; tc++) {
		int a;
		cin >> a;
		int ans = 0, sumCol, sumRow, sumDiag1 = 0, sumDiag2 = 0;
		for (int i = 0; i < 100; i++) {
			sumCol = 0;
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				sumCol += arr[i][j];
				if (i == j)sumDiag1 += arr[i][j];
				if (i + j == 99)sumDiag2 += arr[i][j];
			}
			ans = max(ans,sumCol);
		}
		ans = max(ans, max(sumDiag1,sumDiag2));
		for (int i = 0; i < 100; i++) {
			sumRow = 0;
			for (int j = 0; j < 100; j++) {
				sumRow += arr[j][i];
			}
			ans = max(ans, sumRow);
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}