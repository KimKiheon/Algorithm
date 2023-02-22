import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int n, m, ans;
	static int[][] arr;
	static int[] dx = { 0, 0, -1, 1 }, dy = { 1, -1, 0, 0 };

	static Queue<int[]> q = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 1)
					q.offer(new int[] { i, j });
			}
		}
		while (!q.isEmpty()) {
			int x = q.peek()[0], y = q.poll()[1];
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || arr[nx][ny] == -1 || arr[nx][ny] > 0)
					continue;
				arr[nx][ny] = arr[x][y] + 1;
				q.offer(new int[] { nx, ny });
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					System.out.println(-1);
					return;
				}
				ans = Math.max(ans, arr[i][j]);
			}
		}
		System.out.println(ans-1);
	}

}