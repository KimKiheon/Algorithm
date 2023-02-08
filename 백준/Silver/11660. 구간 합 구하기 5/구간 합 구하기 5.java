
import java.util.Scanner;

public class Main{
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		int n = s.nextInt(), m = s.nextInt(), sum[][] = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sum[i][j] = sum[i][j - 1] + s.nextInt();
			}
		}
		while (m-- > 0) {
			int x1 = s.nextInt(), y1 = s.nextInt(), x2 = s.nextInt(), y2 = s.nextInt();
			int ans = 0;
			if (x1 == x2) {
				sb.append(sum[x2][y2] - sum[x2][y1 - 1]+"\n");
				continue;
			}
			for (int i = x1; i <= x2; i++) {
				ans += sum[i][y2] - sum[i][y1 - 1];
				
			}
			sb.append(ans+"\n");
		}
		System.out.println(sb);
	}
}
