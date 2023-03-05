import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    public static int N, maxCoreCnt, answer;
    public static int[][] arr;
    public static int[] dy = {0, 0, -1, 1};
    public static int[] dx = {-1, 1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder("");
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; ++tc) {
            N = Integer.parseInt(br.readLine());

            arr = new int[N][N];
            maxCoreCnt = 0;
            answer = Integer.MAX_VALUE;

            for (int i = 0; i < N; ++i) {
                st = new StringTokenizer(br.readLine(), " ");
                for (int j = 0; j < N; ++j) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            go(0, 0, 0, 0);

            sb.append("#").append(tc).append(" ").append(answer).append("\n");
        }

        System.out.println(sb);
    }

    public static void go(int x, int y, int coreCnt, int wireLen) {
        if (x == N) {
            if (coreCnt > maxCoreCnt) {
                maxCoreCnt = coreCnt;
                answer = wireLen;
            } else if (coreCnt == maxCoreCnt) {
                answer = (answer > wireLen) ? wireLen : answer;
            }
            return;
        }
        if (y >= N) {
            go(x + 1, 0, coreCnt, wireLen);
            return;
        }
        if (arr[x][y] != 1) {
            go(x, y + 1, coreCnt, wireLen);
            return;
        }

        if (x == N - 1 || y == N - 1 || x == 0 || y == 0) {
            go(x, y + 1, coreCnt + 1, wireLen);
            return;
        }
        boolean flag = true;
        for (int i = 0; i < 4; ++i) {
            if (isConnected(x, y, i)) {
                flag = false;
                int nx = x + dx[i];
                int ny = y + dy[i];
                int len = 0;
                while (nx < N && ny < N && nx >= 0 && ny >= 0) {
                    arr[nx][ny] = 2;
                    nx += dx[i];
                    ny += dy[i];
                    len++;
                }
                go(x, y + 1, coreCnt + 1, wireLen + len);
                nx = x + dx[i];
                ny = y + dy[i];
                while (nx < N && ny < N && nx >= 0 && ny >= 0) {
                    arr[nx][ny] = 0;
                    nx += dx[i];
                    ny += dy[i];
                }
            }
        }
        if (flag) {
            go(x, y + 1, coreCnt, wireLen);
            return;
        }
    }

    public static boolean isConnected(int x, int y, int dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
        while (nx < N && ny < N && nx >= 0 && ny >= 0) {
            if (arr[nx][ny] != 0) return false;
            nx += dx[dir];
            ny += dy[dir];
        }
        return true;
    }
}