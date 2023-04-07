import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Pos implements Comparable<Pos> {
        int x, y; //x, y  -> to, cost

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pos o) {
            return this.y - o.y;
        }
    }

    static final int INF = Integer.MAX_VALUE;

    static int n, m, arr[][], dist[][], islandCnt, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, ans;
    static boolean check[][];
    static boolean visit[];
    static List<Pos>[] list = new ArrayList[7];

    static boolean isValid(int x, int y) {
        return !(x < 0 || x > n - 1 || y < 0 || y > m - 1);
    }

    static PriorityQueue<Pos> pq = new PriorityQueue<>();

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        check = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    //섬 번호 붙이기
    static void getIsland(int x, int y, int cnt) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!isValid(nx, ny) || check[nx][ny] || arr[nx][ny] == 0) continue;
            check[nx][ny] = true;
            arr[nx][ny] = cnt;
            list[cnt].add(new Pos(nx, ny));
            getIsland(nx, ny, cnt);
        }
    }

    //섬간 최단거리 찾기
    static void linkIsland(int dir, int n, int x, int y) {
        int cnt = 0;
        while (true) {
            x += dx[dir];
            y += dy[dir];
            cnt++;
            if (!isValid(x, y) || arr[x][y] == n) break;
            if (cnt < 3 && arr[x][y] > 0) break;
            if (arr[x][y] > 0 && arr[x][y] != n) {
                dist[n][arr[x][y]] = Math.min(dist[n][arr[x][y]], cnt - 1);
                break;
            }
        }
    }

    //최단 거리 구하기
    static void getDist(int n) {
        for (Pos p : list[n]) {
            int x = p.x, y = p.y;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!isValid(nx, ny) || arr[nx][ny] > 0) continue;
                linkIsland(i, n, x, y);
            }
        }
    }

    //MST
    static int prim() {
        int cnt = 0;
        visit = new boolean[islandCnt + 1];
        while (!pq.isEmpty()) {
            int now = pq.peek().x, nowc = pq.poll().y;
            if (visit[now]) continue;
            ans += nowc;
            visit[now] = true;
            cnt++;
            for (int i = 0; i < list[now].size(); i++) {
                int next = list[now].get(i).x;
                int nextc = list[now].get(i).y;
                if (nextc == 1) continue;
                if (!visit[next]) pq.add(new Pos(next, nextc));
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        input();
        //각 섬별로 번호 붙이기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] < 1 || check[i][j]) continue;
                check[i][j] = true;
                arr[i][j] = ++islandCnt;
                list[islandCnt] = new ArrayList<>();
                list[islandCnt].add(new Pos(i, j));
                getIsland(i, j, islandCnt);

            }
        }

        check = new boolean[n][m];
        dist = new int[islandCnt + 1][islandCnt + 1];
        for (int i = 1; i <= islandCnt; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
            getDist(i);
        }
        list = new ArrayList[islandCnt + 1];

        for (int i = 1; i <= islandCnt; i++) {
            list[i] = new ArrayList<>();
            for (int j = 1; j <= islandCnt; j++) {
                if (dist[i][j] < 1 || dist[i][j] == INF) continue;
                list[i].add(new Pos(j, dist[i][j]));
            }
        }

        pq.add(new Pos(1, 0));
        if (prim() != islandCnt) System.out.println(-1);
        else System.out.println(ans);
    }
}