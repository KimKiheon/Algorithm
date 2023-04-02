import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static Queue<Pair> q1 = new LinkedList<>();
    static Queue<Pair> q2 = new LinkedList<>();
    static Queue<Pair> rq = new LinkedList<>();
    static int[][] arr;
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {1, -1, 0, 0};
    static boolean[][] check;
    static int ans, n, m, cnt, xx, time;

    static void del() {
        xx = 0;
        while (!rq.isEmpty()) {
            arr[rq.peek().x][rq.peek().y] = 0;
            ans--;
            rq.remove();
            xx++;
        }
    }

    static void bfs1(int x, int y) {
        q1.add(new Pair(x, y));
        check[x][y] = true;
        while (!q1.isEmpty()) {
            Pair now = q1.peek();
            q1.remove();
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i], ny = now.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (!check[nx][ny] && arr[nx][ny] == 0) {
                    q1.add(new Pair(nx, ny));
                    check[nx][ny] = true;
                } else if (!check[nx][ny] && arr[nx][ny] == 1) {
                    check[nx][ny] = true;
                    rq.add(new Pair(nx, ny));
                }
            }
        }
    }

    static void bfs2(int x, int y) {
        q2.add(new Pair(x, y));
        check[x][y] = true;
        while (!q2.isEmpty()) {
            Pair now = q2.peek();
            q2.remove();
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i], ny = now.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (!check[nx][ny] && arr[nx][ny] == 1) {
                    q2.add(new Pair(nx, ny));
                    check[nx][ny] = true;
                }
            }
        }
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        while (true) {
            time++;
            cnt = 0;
            check = new boolean[n][m];
            bfs1(0, m / 2);
            del();
            check = new boolean[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (!check[i][j] && arr[i][j] == 1) {
                        bfs2(i, j);
                        cnt++;
                    }
            if (cnt == 0) {
                System.out.println(time);
                System.out.println(xx);
                return;
            }
        }
    }
}