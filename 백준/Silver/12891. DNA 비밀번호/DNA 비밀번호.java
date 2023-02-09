import java.util.Deque;
import java.util.Scanner;
import java.util.concurrent.LinkedBlockingDeque;

public class Main {
	static int[] check = new int[26];
	static int[] dna = { 0, 2, 6, 19 };
	static int n, m, ans;
	static String str;
	static Deque<Character> dq = new LinkedBlockingDeque<>();

	static boolean checkDna() {
		for (int i = 0; i < 4; i++)
			if (check[dna[i]] > 0)
				return false;
		return true;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		m = scanner.nextInt();
		scanner.nextLine();
		str = scanner.next();
		for (int i = 0; i < 4; i++) {
			check[dna[i]] = scanner.nextInt();
		}
		for (int i = 0; i < m; i++) {
			char c = str.charAt(i);
			check[c - 'A']--;
			dq.addLast(str.charAt(i));
		}
		if (checkDna())
			ans++;
		for (int i = m; i < n; i++) {
			check[dq.getFirst()-'A']++;
			dq.removeFirst();
			dq.addLast(str.charAt(i));
			check[str.charAt(i) - 'A']--;
			if (checkDna())
				ans++;
		}
		System.out.println(ans);

	}

}