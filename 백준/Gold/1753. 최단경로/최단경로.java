import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static class Edge implements Comparable<Edge> {
		int to, cost;

		public Edge(int to, int cost) {
			super();
			this.to = to;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return this.cost - o.cost;
		}

	}

	static int v, e, start;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb;
	static List<Edge>[] list;
	static int[] dist;

	static PriorityQueue<Edge> pq = new PriorityQueue<>();

	static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		start = Integer.parseInt(br.readLine());
		list = new ArrayList[v + 1];
		dist = new int[v + 1];
		for (int i = 1; i <= v; i++) {
			list[i] = new ArrayList<>();
			dist[i] = Integer.MAX_VALUE;
		}
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			list[from].add(new Edge(to, cost));
		}

	}

	static void dijk() {
		while (!pq.isEmpty()) {
			int cost = pq.peek().cost;
			int now = pq.poll().to;
			if (dist[now] < cost)
				continue;
			for (int i = 0; i < list[now].size(); i++) {
				int next = list[now].get(i).to;
				if (dist[next] > cost + list[now].get(i).cost) {
					dist[next] = cost + list[now].get(i).cost;
					pq.add(new Edge(next, dist[next]));
				}
			}
		}

	}

	public static void main(String[] args) throws IOException {
		input();
		pq.add(new Edge(start, 0));
		dist[start] = 0;
		dijk();
		for (int i = 1; i <= v; i++) {
			if (dist[i] == Integer.MAX_VALUE) {
				System.out.println("INF");
			} else
				System.out.println(dist[i]);
		}
	}
}