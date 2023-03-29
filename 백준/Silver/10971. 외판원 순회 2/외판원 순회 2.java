import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, arr[][], ans = Integer.MAX_VALUE;
	static boolean visited[];

	static void input() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		visited = new boolean[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}

	static void go(int cnt, int now, int sum) {
		if(sum>ans)return;
		if (cnt == n - 1) {
			if(arr[now][0]==0) {
				return;
			}
			ans = Integer.min(ans, sum + arr[now][0]);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (visited[i] || i == 0||arr[now][i]==0)continue;
			visited[i] = true;
			go(cnt + 1, i, sum + arr[now][i]);
			visited[i] = false;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		input();
		go(0, 0, 0);
		System.out.println(ans);
	}

}