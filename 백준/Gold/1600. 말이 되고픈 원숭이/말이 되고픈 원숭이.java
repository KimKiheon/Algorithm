import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Pos {
        int x, y, k, cnt;

        public Pos(int x, int y, int k, int cnt) {
            this.x = x;
            this.y = y;
            this.k = k;
            this.cnt = cnt;
        }
    }

    static int[] dx = {0, 0, -1, 1}, ndx = {-1, -2, -2, -1, 1, 2, 2, 1}, dy = {1, -1, 0, 0}, ndy = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int k, n, m;
    static int[][] arr;
    static boolean[][][] check;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static Queue<Pos> q = new ArrayDeque<>();

    static void input() throws IOException {
        k = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        check = new boolean[n][m][k + 1];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        q.add(new Pos(0, 0, k, 0));
        check[0][0][k] = true;
    }

    static boolean isValid(int x, int y, int k) {
        return !(x < 0 || x > n - 1 || y < 0 || y > m - 1 || check[x][y][k] || arr[x][y] == 1);
    }

    static void go() {
        while (!q.isEmpty()) {
            Pos now = q.poll();
            if (now.x == n - 1 && now.y == m - 1) {
                System.out.println(now.cnt);
                System.exit(0);
            }
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i], ny = now.y + dy[i];
                if (!isValid(nx, ny, now.k)) continue;
                check[nx][ny][now.k] = true;
                q.offer(new Pos(nx, ny, now.k, now.cnt + 1));
            }
            for (int i = 0; i < 8; i++) {
                int nx = now.x + ndx[i], ny = now.y + ndy[i];
                if (now.k == 0 || !isValid(nx, ny, now.k - 1)) continue;
                check[nx][ny][now.k - 1] = true;
                q.offer(new Pos(nx, ny, now.k - 1, now.cnt + 1));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        go();
        System.out.println(-1);
    }
}