import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[][] arr;
	static int n, m;
	static int[] dx = { -1, 0, 1 };
	static int[] dy = { 1, 1, 1 };
	static int ans;

	static int dfs(int x, int y) {
		if(y==m-1) {
			ans++;
			return 1;
		}
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || arr[nx][ny] == 1) {
				continue;
			}
			arr[nx][ny] = 1;
			if(dfs(nx, ny)==1)return 1;
		}
		return 0;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			for (int j = 0; j < s.length(); j++) {
				if (s.charAt(j) == 'x')
					arr[i][j] = 1;
				else
					arr[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			arr[i][0] = 1;
			dfs(i, 0);
		}
		System.out.println(ans);
	}
}