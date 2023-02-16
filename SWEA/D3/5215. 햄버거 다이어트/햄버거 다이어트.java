import java.util.Scanner;

public class Solution {
	static int t, T, n, kcal, ans;
	static int[][] arr;

	static void go(int idx, int sumScore, int sumKcal) {
		if (sumKcal > kcal)
			return;
		if (idx == n) {
			ans = Math.max(ans, sumScore);
			return;
		}
		go(idx + 1, sumScore + arr[idx][0], sumKcal + arr[idx][1]);
		go(idx + 1, sumScore, sumKcal);

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		while (t++ < T) {
			ans = 0;
			n = sc.nextInt();
			kcal = sc.nextInt();
			arr = new int[n][2];
			for (int i = 0; i < n; i++) {
				arr[i][0] = sc.nextInt();
				arr[i][1] = sc.nextInt();
			}
			go(0, 0, 0);
			System.out.println("#" + t + " " + ans);
		}
	}
}