import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/*
1. 브루트 포스로 벽 선택
2. 벽 3개 선택 시 설치
3. 바이러스 bfs or dfs
4. 끝났을 때, 안전구역 count
5. minCount와 비교
6. 브루트 포스 종료 후 minCount 출력
 */
class Pos {
    int x;
    int y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static int maxSafeCnt;
    static int safeCnt;
    static int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
    static int[][] map, map2;
    static List<Pos> virusList;
    static Queue<Pos> q;


    private static boolean isValid(int x, int y) {
        return !(x < 0 || n - 1 < x || y < 0 || m - 1 < y);
    }

    private static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        map2 = new int[n][m];
        virusList = new ArrayList<>();
        q = new ArrayDeque<>();
        maxSafeCnt = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 0) safeCnt++;
                if (map[i][j] == 2) {
                    virusList.add(new Pos(i, j));
                }
            }
        }
    }

    private static void copyMap(int[][] map, int[][] map2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map2[i][j] = map[i][j];
            }
        }
    }

    private static void spreadVirus() {
        int cnt = safeCnt - 3;
        copyMap(map, map2);
        virusList.forEach(q::add);
        while (!q.isEmpty()) {
            Pos now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                if (!isValid(nx, ny)) continue;
                if (map2[nx][ny] == 0) {
                    map2[nx][ny] = 2;
                    q.add(new Pos(nx, ny));
                    cnt--;
                }

            }
        }
        maxSafeCnt = Math.max(maxSafeCnt, cnt);
    }

    private static void selectWall(int cnt) {
        if (cnt == 3) {
            spreadVirus();
            return;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    selectWall(cnt + 1);
                    map[i][j] = 0;
                }
            }
        }

    }


    public static void main(String[] args) throws IOException {
        input();
        selectWall(0);
        System.out.println(maxSafeCnt);

    }

}