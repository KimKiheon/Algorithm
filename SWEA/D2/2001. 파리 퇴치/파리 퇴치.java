import java.util.Scanner;

public class Solution {
	static int N, M;
	static int[][] arr;

	public static int go(int col, int row) {
		int sum = 0;
		for (int i = col; i < col + M; i++) {
			for (int j = row; j < row + M; j++) {
				sum += arr[i][j];
			}
		}
		return sum;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int tc = 0;

		while (tc++ < T) {
			N = sc.nextInt();
			M = sc.nextInt();

			arr = new int[N][N];

			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					arr[i][j] = sc.nextInt(); // 입력

			int max = 0;
			for (int i = 0; i <= N - M; i++) {
				for (int j = 0; j <= N - M; j++) {
					max = Math.max(max, go(i, j));
				}
			}

			System.out.printf("#%d %d%n", tc, max);
		}
	}
}