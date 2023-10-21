import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static boolean[] check = new boolean[26];
	static String[] arr;
	static int n, m, ans;
	static int[] dx = { 0, 0, -1, 1 };
	static int[] dy = { -1, 1, 0, 0 };

	static void dfs(int row, int col, int cnt) {
		ans = Math.max(ans, cnt);
		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i], ny = col + dy[i];
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || check[arr[nx].charAt(ny)-'A'])
				continue;
			int next = arr[nx].charAt(ny)-'A';
			check[next] = true;
			dfs(nx, ny, cnt + 1);
			check[next] = false;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new String[n];
		for (int i = 0; i < n; i++)
			arr[i] = br.readLine();
		check[arr[0].charAt(0) - 'A'] = true;
		dfs(0, 0, 1);
		System.out.println(ans);

	}
}