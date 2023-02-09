import java.util.Scanner;

public class Solution {
	static int T;
	static int n;
	static int[][] arr;
	static int[] dx = { 0, 1, 0, -1 };
	static int[] dy = { 1, 0, -1, 0 };
	static int d = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = 0;
		T = sc.nextInt();
		while (t++ < T) {
			int cnt = 1;
			int x = 0, y = 0;
			n = sc.nextInt();
			arr = new int[n][n];
			arr[0][0] = cnt++;
			while (cnt <= n * n) {
				d = d % 4;
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != 0) {
					d++;
					continue;
				}
				arr[nx][ny] = cnt++;
				x = nx;
				y = ny;
			}
			System.out.println("#" + t);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					System.out.printf("%d ", arr[i][j]);
				}
				System.out.println();
			}
		}
	}
}