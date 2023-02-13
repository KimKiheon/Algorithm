import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt(), tmp, arr[] = new int[n + 1];
		List<Integer> list = new ArrayList<>();
		list.add(k);
		for (int i = 1; i <= n; i++)
			arr[i] = 1;
		arr[k] = -1;
		int i = k, t = n;
		while (t - 1 > 0) {
			tmp = k;
			while (tmp > 0) {
				i++;
				if (i > n)i = 1;
				if (arr[i] == 1)tmp--;
			}
			list.add(i);
			arr[i] = -1;
			t--;
		}
		String s = list.toString().replace('[', '<').replace(']', '>');
		System.out.println(s);

	}
}