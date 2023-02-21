import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int n;
	static char[][] arr;
	static StringBuilder sb = new StringBuilder();

	static void go(int x, int y, int size) {
		int sum = 0;
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (arr[i][j] == '1') sum++;
			}
		}
		if (sum == size * size) {
			sb.append(1);
			return;
		}
		if (sum == 0) {
			sb.append(0);
			return;
		}
		sb.append('(');
		int s = size / 2;
		go(x, y, s);
		go(x, y + s, s);
		go(x + s, y, s);
		go(x + s, y + s, s);
		sb.append(')');
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr = new char[n][n];
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			arr[i] = s.toCharArray();
		}
		go(0, 0, n);
		System.out.println(sb);
	}
}