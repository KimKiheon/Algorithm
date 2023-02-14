import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	static int N, t;
	static StringBuilder sb = new StringBuilder();
	static boolean flag = false;
	static boolean check(char c) {
		return c >= '0' && c <= '9';
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while (t++ < 10) {
			N = Integer.parseInt(br.readLine());
			flag = true;
			if(N%2==0)flag = false;
			for(int i=0;i<N;i++) {
				String[] strings = br.readLine().split(" ");
				if(strings.length==2&&!check(strings[1].charAt(0)))flag=false;
				if(strings.length==4&&check(strings[1].charAt(0)))flag=false;	
			}
			sb.append("#"+t);
			if(!flag)sb.append(" 0\n");
			else sb.append(" 1\n");
		}
		System.out.println(sb.toString());
	}
}