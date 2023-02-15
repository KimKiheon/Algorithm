import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static List<ArrayList<Integer>> adj;
	static boolean check[];
	static void dfs(int now) {
		if (check[now] == true)
			return;
		check[now] = true;
		System.out.print(now + " ");
		for (int i = 0; i < adj.get(now).size(); i++)
			if (!check[adj.get(now).get(i)])
				dfs(adj.get(now).get(i));
	}

	static void bfs(int start) {
		Queue<Integer> q = new LinkedList<>();

		q.add(start);
		check[start] = true;

		while (!q.isEmpty()) {
			int now = q.poll();
			System.out.print(now + " ");

			for (int i = 0; i < adj.get(now).size(); i++) {
				if (!check[adj.get(now).get(i)]) {
					q.add(adj.get(now).get(i));
					check[adj.get(now).get(i)] = true;
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt(), m = sc.nextInt(), start = sc.nextInt();

		adj = new ArrayList<ArrayList<Integer>>();
		check = new boolean[n + 1];
		for (int i = 0; i <= n; i++)
			adj.add(new ArrayList<Integer>());

		for (int i = 0; i < m; i++) {
			int v1 = sc.nextInt();
			int v2 = sc.nextInt();
			adj.get(v1).add(v2);
			adj.get(v2).add(v1);
		}
		for (int i = 1; i <= n; i++)
			Collections.sort(adj.get(i));
		dfs(start);
		Arrays.fill(check, false);
		System.out.println();
		bfs(start);
	}
}