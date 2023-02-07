import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

class Solution
{
    static int tc = 0;
	static PriorityQueue<Integer> pqAsc = new PriorityQueue<>();
	static PriorityQueue<Integer> pqDesc = new PriorityQueue<>(Collections.reverseOrder());
	static int n;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int num;
		Scanner scanner = new Scanner(System.in);
		while (tc++ != 10) {
			n = scanner.nextInt();
			for (int i = 0; i < 100; i++) {
				num = scanner.nextInt();
				pqDesc.add(num);
				pqAsc.add(num);
			}
			for (int i = 0; i < n; i++) {
				int max = pqDesc.poll();
				int min = pqAsc.poll();
				pqDesc.add(max - 1);
				pqAsc.add(min + 1);
			}
			System.out.println("#"+tc+" "+(pqDesc.peek()-pqAsc.peek()));
			pqAsc.clear();
			pqDesc.clear();
		}
	}
}