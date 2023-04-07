import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int n, m, t, cnt;
    static List<Integer>[] child, parent;
    static boolean[] check;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        child = new ArrayList[n + 1];
        parent = new ArrayList[n + 1];
        check = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            child[i] = new ArrayList<>();
            parent[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            child[a].add(b);
            parent[b].add(a);
        }
    }

    static void dfs(List<Integer>[] list, int now) {
        for (int next : list[now]) {
            if (check[next]) continue;
            check[next] = true;
            dfs(list, next);
            cnt++;
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cnt = 0;
            check = new boolean[n + 1];
            check[i] = true;
            dfs(child, i);
            dfs(parent, i);
            if (cnt == n - 1) ans++;
        }
        System.out.println(ans);
    }
}