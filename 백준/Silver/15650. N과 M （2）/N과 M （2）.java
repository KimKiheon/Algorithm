
import java.util.Scanner;

public class Main {
	static int N, M;
	static int[] arr;

	static void go(int cnt, int startNum) {
		if (cnt == M) {
			for (int i = 0; i < cnt; i++) {
				System.out.printf("%d ", arr[i]);
			}
			System.out.println();
			return;
		}
		for (int i = startNum; i <= N; i++) {
			arr[cnt] = i;
			go(cnt + 1, i + 1);
			arr[cnt] = 0;

		}

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		arr = new int[M];
		go(0, 1);
	}

}
