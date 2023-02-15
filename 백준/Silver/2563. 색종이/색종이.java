import java.util.Scanner;

public class Main {
	static int[][] check = new int [105][105];
	static int N, ans;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		while (N-- > 0) {
			int a = sc.nextInt(), b = sc.nextInt();
			for (int i = a; i < a + 10; i++) {
				for (int j = b; j < b + 10; j++) {
					if (check[i][j] == 0) {
						check[i][j] = 1;
						ans++;
					}

				}
			}
		}
		System.out.println(ans);
	}

}