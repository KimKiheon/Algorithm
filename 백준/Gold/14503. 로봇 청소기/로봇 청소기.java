import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static int x, y, dir;

    static int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    static int[][] map;
    static boolean[][] cleaned;
    static int ans;

    /*
    1. 현재 칸 청소 안했으면 청소
    2. 주변 4칸 청소 다했으면
        1)방향 유지 및 후진 1칸
        2)뒤쪽이 벽이라 이동할 수 없으면 종료
    3. 주변 4칸 중 청소할 곳 있으면
        1) 반시계 방향 회전
        2) 정면 청소 안되있으면 이동
     */
    private static boolean isValid(int x, int y) {
        return !(x < 0 || n - 1 < x || y < 0 || m - 1 < y);
    }

    private static boolean isCleanAround(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!isValid(nx, ny)) continue;
            if (map[nx][ny] == 0 && !cleaned[nx][ny]) {
                return false;
            }
        }
        return true;
    }

    private static boolean isWall(int x, int y) {
        return (map[x][y] == 1);
    }

    private static void clean() {
        while (true) {
            if (map[x][y] == 0 && !cleaned[x][y]) {
                cleaned[x][y] = true;
                ans++;
            }
            if (isCleanAround(x, y)) {
                int nx = x - dx[dir];
                int ny = y - dy[dir];
                if (!isValid(nx, ny)) continue;
                if (isWall(nx, ny)) return;
                x = nx;
                y = ny;

            } else {
                while (true) {
                    dir = (dir + 1) % 4;
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (!isValid(nx, ny) || isWall(nx, ny) || cleaned[nx][ny]) continue;
                    x = nx;
                    y = ny;
                    break;
                }
            }

        }
    }

    private static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        cleaned = new boolean[n][m];
        st = new StringTokenizer(br.readLine());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        dir = Integer.parseInt(st.nextToken());
        if (dir % 2 == 1) {
            dir = (dir + 2) % 4;
        }
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }


    public static void main(String[] args) throws IOException {
        input();
        clean();
        System.out.println(ans);

    }

}