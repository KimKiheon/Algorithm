import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, r, c, ans, max;
	static void go(int row, int col, int s) {
		if (row == r && col == c) {
			System.out.println(ans);
			return;
		}
		if (row<=r && r < row + s && col <= c && c < col + s) {
			int ss=s/2;
			go(row, col, ss);
			go(row, col + ss, ss);
			go(row + ss, col, ss);
			go(row + ss, col + ss, ss);
			return;
		}
		ans += s * s;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		max = 1 << n;
		go(0, 0, max);

	}

}