#include<stdio.h>
int main(void) {
	int C;
	int N;
	double arr[1000];
	double avg = 0;
	scanf("%d", &C);
	int cnt=0;
	for (int i = 0; i < C; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%lf", &arr[j]);
			avg += arr[j];
		}
		avg /= N;
		for (int j = 0; j < N; j++) {
			if (arr[j] > avg)
				cnt++;
		}
		printf("%.3f%%\n", (double)cnt / N * 100);
		cnt = 0;
		avg = 0;
	}
	return 0;
}