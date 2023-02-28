import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	static int n, people[];
	static ArrayList<Integer>[] list, area;
	static ArrayList<Integer> ans;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static boolean[] select, check;
	static int cnt;

	static boolean dfs(int now, boolean key) {
		for (Integer next : list[now]) {
			if (select[next] != key || check[next])
				continue;
			check[next]=true;
			cnt--;
			dfs(next, key);

		}
		return cnt == 0 ? true : false;
	}

	static void go() {
		area[0] = new ArrayList<>();
		area[1] = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (select[i])
				area[0].add(i);
			else
				area[1].add(i);
		}
		if (area[0].isEmpty() || area[1].isEmpty())
			return;
		int tmp1 = area[0].get(0), tmp2 = area[1].get(0);
		check = new boolean[n];
		check[tmp1] = true;
		cnt = area[0].size() - 1;
		boolean a = dfs(tmp1, true);
		check = new boolean[n];
		check[tmp2] = true;
		cnt = area[1].size() - 1;
		boolean b = dfs(tmp2, false);
		if (a && b) {
			int s1 = 0, s2 = 0;
			for (int i = 0; i < n; i++) {
				if (select[i])
					s1 += people[i];
				else
					s2 += people[i];
			}
			ans.add(Math.abs(s1 - s2));
		}
	}

	static void subSet(int idx) {
		if (idx == n) {
			area = new ArrayList[2];
			go();
			return;
		}
		subSet(idx + 1);
		select[idx] = true;
		subSet(idx+1);
		select[idx] = false;
	}

	static void input() throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		people = new int[n];
		check = new boolean[n];
		list = new ArrayList[n];
		select = new boolean[n];
		ans = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			people[i] = Integer.parseInt(st.nextToken());
			list[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int tmp = Integer.parseInt(st.nextToken());
			for (int j = 0; j < tmp; j++) {
				list[i].add(Integer.parseInt(st.nextToken()) - 1);
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		input();
		subSet(0);
		Collections.sort(ans);
		if (ans.size() == 0) {
			System.out.println(-1);
			return;
		}
		System.out.println(ans.get(0));
	}
}