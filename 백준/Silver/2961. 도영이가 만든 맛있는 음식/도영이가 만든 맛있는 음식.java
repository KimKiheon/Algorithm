import java.util.Scanner;

public class Main {
	static int[][] arr;
	static int N;
	static int ans=(int)2e9;

	static void go(int idx, int sum, int mul) {
		if (idx == N) {
			if (sum == 0)return;
			ans = Math.min(ans,Math.abs(mul - sum));
			return;
		}
		go(idx + 1, sum + arr[idx][1], mul * arr[idx][0]);
		go(idx + 1, sum, mul);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N][2];
		for (int i = 0; i < N; i++) {
			arr[i][0] = sc.nextInt();
			arr[i][1] = sc.nextInt();
		}
		go(0, 0, 1);
		System.out.println(ans);

	}
}