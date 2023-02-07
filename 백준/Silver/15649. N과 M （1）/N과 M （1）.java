import java.util.Scanner;

public class Main {
	static int[] check = new int[9];
	static int[] arr = new int[9];
	static int n, m;
	static StringBuilder sb = new StringBuilder();

	static void go(int now) {
		if (now == m) {
			for (int i = 0; i < now; i++) {
				sb.append(arr[i]+" ");
			}
			sb.append("\n");
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == 1)continue;
			check[i] = 1;
			arr[now] = i;
			go(now + 1);
			arr[now] = 0;
			check[i] = 0;

		}
		return;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		m = scanner.nextInt();
		go(0);
		System.out.println(sb.toString());
	}
}
