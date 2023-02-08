
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n, m;
		n = scanner.nextInt();
		m = scanner.nextInt();
		int[] sum = new int[n];
		for (int i = 0; i < n; i++) {
			int a = scanner.nextInt();
			if (i == 0) {
				sum[i]=a;
				continue;
			}
			sum[i] = a + sum[i - 1];
		}
		while (m-- > 0) {
			int from, to;
			from = scanner.nextInt();
			to = scanner.nextInt();
			int ans;
			if (from == 1) {
				System.out.println(sum[to - 1]);
				continue;
			}
			System.out.println(sum[to - 1] - sum[from - 2]);

		}

	}
}
