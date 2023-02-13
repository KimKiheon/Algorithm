import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<int[]> s = new Stack<>();
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            int x = Integer.parseInt(st.nextToken());
            while (!s.isEmpty()) {
                if (s.peek()[1] >= x) {
                    sb.append(s.peek()[0] + " ");
                    break;
                }
                s.pop();
            }
            if (s.isEmpty()) sb.append("0 ");
            s.push(new int[]{i, x});
        }
        System.out.println(sb.toString());
    }
}