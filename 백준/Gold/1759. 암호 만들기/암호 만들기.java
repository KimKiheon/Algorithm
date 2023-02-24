import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int n, m;
	static char[] arr;
	static char[] vowel = { 'a', 'e', 'i', 'o', 'u' };
	static List<Character> list = new ArrayList<Character>();
	static StringBuilder sb = new StringBuilder();

	static void com(int start, int cnt) {
		if (cnt == m) {
			int tmp1 = 0, tmp2 = 0;
			for (char c : list) {
				boolean flag = false;
				for (int i = 0; i < 5; i++) {
					if (c == vowel[i])flag=true;
				}
				if(flag)tmp1++;
				else tmp2++;
			}
			if (tmp1==0||tmp2<2) return;
				for(char c:list) sb.append(c);
			sb.append("\n");
		}
		
		for (int i = start; i < n; i++) {
			list.add(arr[i]);
			com(i + 1, cnt + 1);
			list.remove(list.size() - 1);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();
		n = sc.nextInt();
		arr = new char[n];
		for (int i = 0; i < n; i++)
			arr[i] = sc.next().charAt(0);
		Arrays.sort(arr);
		com(0, 0);
		System.out.println(sb);
	}

}