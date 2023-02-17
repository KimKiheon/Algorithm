import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int[] arr = new int[9];
		int sum = 0;
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 9; i++) {
			arr[i] = sc.nextInt();
			sum += arr[i];
		}
		for (int i = 0; i < 8; i++) {
			for (int j = i + 1; j < 9; j++) {
				if (sum - (arr[i] + arr[j]) == 100) {
					arr[i] = arr[j] = 0;
					for (int a : arr) {
						if (a == 0)	continue;
						System.out.println(a);
					}
					return;
				}
			}
		}
	}
}