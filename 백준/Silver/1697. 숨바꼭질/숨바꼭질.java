import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int n, m;
	static Queue<Integer> q = new LinkedList<Integer>();
	static int[] check = new int[100001];
	static void find(int now, int next) {
		if(next<0||next>100000)return;
		if(check[next]>check[now]+1) {
			check[next]=check[now]+1;
			q.offer(next);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		q.offer(n);
		for (int i = 0; i < check.length; i++)check[i] = 10000000;
		check[n] = 0;
		while (!q.isEmpty()) {
			int now = q.poll();
			int[] next = { now - 1, now + 1, now * 2 };
			if (now == m)
				break;
			for (int i = 0; i < 3; i++) {
				find(now, next[i]);
			}
		}
		System.out.println(check[m]);
	}
}