
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	static int N;
	static StringBuilder sb=new StringBuilder();
	static void go(int n, int start, int by, int to) {
		if (n == 1) {
			sb.append(start+" "+to+"\n");
			return;
		}
		go(n - 1, start, to, by);
		sb.append(start+" "+to+"\n");
		go(n - 1, by, start, to);
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		BigInteger bigInteger = BigInteger.ONE;
		System.out.println(bigInteger.shiftLeft(N).subtract(BigInteger.ONE).toString());
		if (N <= 20) {
			go(N, 1, 2, 3);
			System.out.println(sb.toString());
		}
	}
}
