import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static long nums[], tree[];
    static int n, m, k;

    static void update(int i, long num) {
        while (i <= n) {
            tree[i] += num;
            i += (i & -i);
        }
    }

    static long sum(int i) {
        long ans = 0;
        while (i > 0) {
            ans += tree[i];
            i -= (i & -i);
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        nums = new long[n + 1];
        tree = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            nums[i] = Long.parseLong(br.readLine());
            update(i, nums[i]);
        }
        int x = m + k;
        while (x-- > 0) {
            int a, b;
            long c;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Long.parseLong(st.nextToken());
            if (a == 1) {
                long tmp = c - nums[b];
                nums[b] = c;
                update(b, tmp);
            } else sb.append(sum((int) c) - sum(b - 1)).append("\n");
        }
        System.out.println(sb);
    }
}