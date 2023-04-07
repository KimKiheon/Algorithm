import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Pos {
        int x, y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static boolean isValid(int x, int y) {
        return !(x < 0 || x > n-1 || y < 0 || y > m - 1);
    }

    static int n, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, ans;
    static char[][] arr;
    static boolean[][] check;
    static Queue<Pos> q, waterQ;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new char[n][m];
        check = new boolean[n][m];
        q = new ArrayDeque<>();
        waterQ = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == 'S') q.add(new Pos(i, j));
                else if (arr[i][j] == '*') waterQ.add(new Pos(i, j));
            }
        }
    }

    static void water() {
        int s = waterQ.size();
        while (s-- > 0) {
            int x = waterQ.peek().x, y = waterQ.poll().y;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!isValid(nx, ny) || arr[nx][ny] != '.') continue;
                arr[nx][ny] = '*';
                waterQ.add(new Pos(nx, ny));
            }
        }
    }

    static void bfs(int x, int y) {
        check[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!isValid(nx, ny) || check[nx][ny]) continue;
            if (arr[nx][ny] == 'D') {
                System.out.println(ans);
                System.exit(0);
            } else if (arr[nx][ny] == '.') {
                q.add(new Pos(nx, ny));
                check[nx][ny] = true;
            }

        }

    }
    public static void main(String[] args) throws IOException {
        input();
        while (true) {
            ans++;
            int s = q.size();
            if(s==0)break;
            water();
            for (int i = 0; i < s; i++) {
                int x = q.peek().x, y = q.poll().y;
                arr[x][y] = '.';
                bfs(x, y);
            }
        }
        System.out.println("KAKTUS");
    }
}