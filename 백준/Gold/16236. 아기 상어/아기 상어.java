import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static class Fish implements Comparable<Fish> {
		int s, x, y;

		public Fish(int s, int x, int y) {
			super();
			this.s = s;
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Fish o) {
			if (this.s == o.s) {
				if (this.x == o.x)
					return this.y - o.y;
				return this.x - o.x;
			}
			return this.s - o.s;
		}
	}

	static class Pos {
		int x, y;

		public Pos(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	static int n, ans, sharkSize = 2, expe = 2;
	static int[][] arr, check;
	static int[] dx = { 0, 0, -1, 1 }, dy = { 1, -1, 0, 0 };
	static Pos now;
	static List<Fish> canEat;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Queue<Pos> q = new LinkedList<>();
	static StringTokenizer st;

	static boolean inValid(int x, int y) {
		return !(x < 0 || x > n - 1 || y < 0 || y > n - 1);
	}

	static void input() throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		check = new int[n][n];
		canEat=new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 9) {
					now = new Pos(i, j);
					arr[i][j] = 0;
				}
			}
		}
	}

	static int bfs() {
		q.add(now);
		while (!q.isEmpty()) {
			int x = q.peek().x, y = q.poll().y;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!inValid(nx, ny) || arr[nx][ny] > sharkSize || check[nx][ny] > 0)
					continue;
				check[nx][ny] = check[x][y] + 1;
				q.add(new Pos(nx, ny));
				if (arr[nx][ny] > 0 && arr[nx][ny] < sharkSize) {
					canEat.add(new Fish(check[nx][ny], nx, ny));
				}
			}
		}
		return canEat.size();
	}

	static void eat(Fish target) {
		ans += check[target.x][target.y];
		arr[target.x][target.y] = 0;
		now.x = target.x;
		now.y = target.y;
		expe--;
		if (expe == 0) {
			expe = ++sharkSize;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		input();
		while (bfs() > 0) {
			Collections.sort(canEat);
			Fish target = canEat.get(0);
			eat(target);
			for(int[] i: check)Arrays.fill(i, 0);
			canEat.clear();
		}
		System.out.println(ans);
	}

}