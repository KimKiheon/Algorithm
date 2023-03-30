import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Pos implements Comparable<Pos> {
        int x, y, cost;

        public Pos(int x, int y, int cost) {
            super();
            this.x = x;
            this.y = y;
            this.cost = cost;
        }

        @Override
        public int compareTo(Pos o) {
            return this.cost - o.cost;
        }
    }

    static int n, arr[][], dist[][], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    static PriorityQueue<Pos> pq;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static boolean isValid(int x, int y) {
        return !(x < 0 || x > n - 1 || y < 0 || y > n - 1);
    }

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        if (n == 0) {
            System.exit(0);
        }
        arr = new int[n][n];
        dist = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        pq = new PriorityQueue<>();
        dist[0][0] = arr[0][0];
        pq.add(new Pos(0, 0, dist[0][0]));
    }

    static void dijk() {
        while (!pq.isEmpty()) {
            Pos now = pq.poll();
            int x = now.x, y = now.y, c = now.cost;
            if (c > dist[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!isValid(nx, ny)) continue;
                int nc = arr[nx][ny] + c;
                if (dist[nx][ny] > nc) {
                    dist[nx][ny] = nc;
                    pq.add(new Pos(nx, ny, dist[nx][ny]));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        int cnt = 0;
        while (++cnt > 0) {
            input();
            dijk();
            System.out.println("Problem " + cnt + ": " + dist[n - 1][n - 1]);
        }

    }
}