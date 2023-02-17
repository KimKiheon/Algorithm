import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int ans = (int) 2e9;
	static boolean selected[];
	static int n, m;
	static List<int[]> chicken, home, q;
	static Scanner sc = new Scanner(System.in);

	static void input() {
		n = sc.nextInt();
		m = sc.nextInt();
		chicken = new ArrayList<int[]>();
		home = new ArrayList<int[]>();
		q = new ArrayList<int[]>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a = sc.nextInt();
				if (a == 2) {
					chicken.add(new int[] { i, j });
				}
				if (a == 1) {
					home.add(new int[] { i, j });
				}
			}
		}
		selected = new boolean[chicken.size()];
	}

	static void go() {
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int dist = (int) 2e9;
			for (int j = 0; j < q.size(); j++) {
				int x = q.get(j)[0], y = q.get(j)[1];
				dist = Math.min(dist, Math.abs(x - home.get(i)[0]) + Math.abs(y - home.get(i)[1]));
			}
			sum += dist;
		}
		ans = Math.min(ans, sum);
	}

	static void combination(int idx, int cnt) {
		if (cnt == m) {
			q.clear();
			for (int i = 0; i < chicken.size(); i++) {
				if (selected[i]) {
					int x = chicken.get(i)[0], y = chicken.get(i)[1];
					q.add(new int[] { x, y });
				}
			}
			go();
			return;
		}
		for (int i = idx; i < chicken.size(); i++) {
			if (!selected[i]) {
				selected[i] = true;
				combination(i + 1, cnt + 1);
				selected[i] = false;
			}
		}
	}

	public static void main(String[] args){
		input();
		combination(0, 0);
		System.out.println(ans);
	}
}