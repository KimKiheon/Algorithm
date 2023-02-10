import java.util.Scanner;

public class Solution {
	static int[] arr = new int[8];
	static int N;
	static int t;
	static int idx;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (t++ < 10) {
			N = sc.nextInt();
			for (int i = 0; i < 8; i++) {
				arr[i] = sc.nextInt();
			}
			for (int i = 0;; i++) {
				arr[i % 8] -= (i % 5) + 1;
				if (arr[i % 8] < 1) {
					arr[i % 8] = 0;
					idx = (i % 8) + 1;
					break;
				}
			}
			System.out.printf("#%d", t);
			for (int i = idx; i < idx + 8; i++) {
				System.out.printf(" %d", arr[i % 8]);
			}
			System.out.println();
		}
	}
}