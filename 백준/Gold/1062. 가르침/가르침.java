import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int d = 0;
	static int n, k, ans;
	static String[] arr;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static boolean[] check = new boolean[26];
	static char[] origin = { 'a', 'c', 'i', 'n', 't' };

	static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		arr = new String[n];
		for (int i = 0; i < 5; i++)	check[origin[i] - 'a'] = true;
		for (int i = 0; i < n; i++)	arr[i] = br.readLine();
	}

	static void go() { //알파벳 조합 후 완전 탐색
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			String str = arr[i];
			boolean flag = true;
			for (int j = 0; j < str.length(); j++) {
				if (!check[str.charAt(j) - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag)
				cnt++;
		}
		ans = Math.max(ans, cnt);

	}

	static void com(int start, int cnt) { //조합
		if (cnt == k) { //조합 후 완탐
			go();
			return;
		}
		for (int i = start; i < 26; i++) {
			if (check[i])continue;
			check[i] = true;
			com(i + 1, cnt + 1);
			check[i] = false;

		}
	}

	public static void main(String[] args) throws IOException {
		input(); //입력
		k -= 5;
		com(0, 0);
		System.out.println(ans);

	}
}