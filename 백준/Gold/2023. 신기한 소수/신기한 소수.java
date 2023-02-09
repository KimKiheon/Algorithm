import java.util.Scanner;

public class Main {
	static int[] arr = { 2, 3, 5, 7 };
	static int N;

	static boolean isPrime(int n) {
		if (n == 1 || n == 0)
			return false;
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}

	static void go(int first, int cnt) {
		if (cnt == 0)
			System.out.println(first);
		for (int i = 1; i < 10; i += 2) {
			int tmp = first * 10 + i;
			if (isPrime(tmp))
				go(tmp, cnt - 1);
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		for (int i = 0; i < 4; i++) {
			go(arr[i], N - 1);
		}
	}

}