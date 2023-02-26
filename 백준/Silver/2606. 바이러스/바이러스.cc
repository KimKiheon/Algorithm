#include<iostream>
using namespace std;
int N, arr[101][101], t, cnt;
int main() {
	scanf("%d", &N);
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (arr[1][i])
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}
