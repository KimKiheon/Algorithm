import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, arr[][];
    static long dp[][][];

    static boolean isValid(int x, int y) {
        return !(x < 0 || x > n - 1 || y < 0 || y > n - 1);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        dp = new long[n][n][3];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    //H,V,D
    static void go() {
        dp[0][1][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (arr[i][j] == 1 || (i == 0 && j == 1)) continue;
                if (arr[i][j - 1] != 1) { //가로
                    dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
                }
                if (i > 0 && arr[i - 1][j] != 1) { //세로
                    dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
                }
                if (i > 0 && arr[i - 1][j - 1] != 1 && arr[i - 1][j] != 1 && arr[i][j - 1] != 1) { //대각선
                    dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        go();
        System.out.println(dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2]);

    }
}