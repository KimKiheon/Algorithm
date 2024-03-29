import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	static int[] check = new int[26];
	static char[] dna = { 0, 2, 6, 19 };
	static int n, m, ans;
	static String str;
	static Deque<Character> dq = new LinkedList<>();

	static boolean checkDna() {
		for (int i = 0; i < 4; i++)	if (check[dna[i]] > 0)return false;
		return true;
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		m = scanner.nextInt();
		scanner.nextLine();
		str = scanner.next();
		for (int i = 0; i < 4; i++)	check[dna[i]] = scanner.nextInt();
		for (int i = 0; i < m; i++) {
			check[str.charAt(i) - 'A']--;
			dq.addLast(str.charAt(i));
		}
		if (checkDna())	ans++;
		for (int i = m; i < n; i++) {
            char c = str.charAt(i);
			check[dq.getFirst()-'A']++;
			dq.removeFirst();
			dq.addLast(c);
			check[c - 'A']--;
			if (checkDna())	ans++;
		}
		System.out.println(ans);
	}
}