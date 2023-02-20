import java.util.Scanner;

public class Main {
	static int n, r, c, ans, max;
	static Scanner sc = new Scanner(System.in);

	static void go(int row, int col, int s) {
		if (row == r && col == c) {
			System.out.println(ans);
			return;
		}
		if (row<=r && r < row + s && col <= c && c < col + s) {
			int ss=s/2;
			go(row, col, ss);
			go(row, col + ss, ss);
			go(row + ss, col, ss);
			go(row + ss, col + ss, ss);
			return;
		}
		ans += s * s;
	}

	public static void main(String[] args) {
		n = sc.nextInt();
		r = sc.nextInt();
		c = sc.nextInt();
		max = 1 << n;
		go(0, 0, max);

	}

}