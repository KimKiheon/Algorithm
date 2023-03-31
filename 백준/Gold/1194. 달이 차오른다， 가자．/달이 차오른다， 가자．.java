import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Pos {
        int x, y, key = 0, cnt = 0;

        public Pos(int x, int y, int key, int cnt) {
            this.x = x;
            this.y = y;
            this.key = key;
            this.cnt = cnt;
        }
    }

    static boolean check[][][];
    static int n, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
    static char arr[][];
    static Queue<Pos> q = new ArrayDeque<>();
    static Pos start;

    static boolean isValid(int x, int y) {
        return !(x < 0 || x > n - 1 || y < 0 || y > m - 1);
    }

    static void go() {
        q.add(start);
        while (!q.isEmpty()) {
            Pos now = q.poll();
            for (int i = 0; i < 4; i++) {
            int x = now.x, y = now.y, k = now.key, c = now.cnt;
                int nx = x + dx[i], ny = y + dy[i];

                if (!isValid(nx, ny) || arr[nx][ny] == '#' || check[nx][ny][k]) continue;

                if (arr[nx][ny] == '1') {
                    System.out.println(c+1);
                    System.exit(0);
                }

                if ('A' <= arr[nx][ny] && arr[nx][ny] <= 'F') {
                    int tmp = 1 << (arr[nx][ny] - 'A');
                    if ((tmp & k) == 0) {
                        check[nx][ny][k] = true;
                        continue;
                    }
                }

                else if ('a' <= arr[nx][ny] && arr[nx][ny] <= 'f') {
                    k |= 1 << (arr[nx][ny] - 'a');
                }

                check[nx][ny][k] = true;
                q.add(new Pos(nx, ny, k,c+1));
            }

        }
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new char[n][m];
        check = new boolean[n][m][1 << 6];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == '0') {
                    start = new Pos(i, j, 0,0);
                    check[i][j][0]=true;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        go();
        System.out.println(-1);
    }

}