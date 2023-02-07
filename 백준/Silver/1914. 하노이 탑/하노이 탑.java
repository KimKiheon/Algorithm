
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	static int N;

	static void go(int n, int start, int by, int to) {
		if (n == 1) {
			System.out.println(start + " " + to);
			return;
		}
		go(n - 1, start, to, by);
		System.out.println(start + " " + to);
		go(n - 1, by, start, to);
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		BigInteger bigInteger = BigInteger.ONE;
		System.out.println(bigInteger.shiftLeft(N).subtract(BigInteger.ONE).toString());
		if (N <= 20)go(N, 1, 2, 3);

	}

}
