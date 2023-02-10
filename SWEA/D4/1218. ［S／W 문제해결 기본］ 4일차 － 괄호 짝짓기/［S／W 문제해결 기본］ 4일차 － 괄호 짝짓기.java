import java.util.Scanner;
import java.util.Stack;

public class Solution {
	static String str;
	static Stack<Character> st;
	static int t;
	static boolean flag;

	static void print(int n) {
		System.out.println("#" + t + " " + n);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (t++ < 10) {
			flag = true;
			st = new Stack<>();
			sc.nextInt();
			sc.nextLine();
			str = sc.nextLine();
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				if (c == '(' || c == '{' || c == '<' || c == '[') {
					st.add(c);
					continue;
				}
				if (c == ')' && st.pop() == '(')
					continue;
				if (c == ']' && st.pop() == '[')
					continue;
				if (c == '>' && st.pop() == '<')
					continue;
				if (c == '}' && st.pop() == '{')
					continue;
				flag = false;
				break;

			}
			if (st.isEmpty() && flag)
				print(1);
			else
				print(0);
		}
	}

}