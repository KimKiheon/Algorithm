import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, kind, k, coupon, arr[], check[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        kind = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        coupon = Integer.parseInt(st.nextToken());
        check = new int[kind + 1];
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int cnt = 0, ans = 0;
        for (int i = 0; i < k; i++) {
            if (check[arr[i]] == 0) cnt++;
            check[arr[i]]++;
        }
        for (int i = k; i < k + n; i++) {
            if (--check[arr[i - k]] == 0) cnt--;
            int idx = i%n;

            if (check[arr[idx]] == 0) cnt++;
            check[arr[idx]]++;
            if(check[coupon]==0)cnt++;
            ans = Math.max(ans, cnt);
            if(check[coupon]==0)cnt--;
        }
        System.out.println(ans);
    }
}