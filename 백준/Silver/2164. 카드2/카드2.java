import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static Queue<Integer> q = new LinkedList<>();
	static int N;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		if (N == 1) {
			System.out.println(1);
			return;
		}
		for (int i = 1; i <= N; i++)
			q.add(i);
		while (q.size() != 1) {
			q.poll();
			if (q.size() == 1) {
				System.out.println(q.peek());
				break;
			}
			q.add(q.poll());
		}
	}

}