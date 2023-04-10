import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int arr[][], paper[] = {0, 5, 5, 5, 5, 5}, ans = Integer.MAX_VALUE, paperCnt;

    static boolean isValid(int x, int y, int s) {
        if (10 < x + s || 10 < y + s || paper[s] == 0) return false;
        for (int i = x; i < x + s; i++) {
            for (int j = y; j < y + s; j++) if (arr[i][j] == 0) return false;

        }
        return true;
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        arr = new int[10][10];
        for (int i = 0; i < 10; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 10; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 1) paperCnt++;
            }
        }
    }

    static void add(int x, int y, int s) {
        paper[s]--;
        for (int i = x; i < x + s; i++) {
            for (int j = y; j < y + s; j++) {
                arr[i][j] = 0;
            }
        }
        paperCnt -= s * s;
        return;
    }

    static void delete(int x, int y, int s) {
        paper[s]++;
        for (int i = x; i < x + s; i++) {
            for (int j = y; j < y + s; j++) {
                arr[i][j] = 1;
            }
        }
        paperCnt += s * s;
        return;
    }

    static void go(int x, int y, int cnt) {
        if (paperCnt == 0) {
            ans = Math.min(ans, cnt);
            return;
        }
        if (cnt > ans) return;
        for (int i = x; i < 10; i++) {
            for (int j = y; j < 10; j++) {
                if (arr[i][j] == 1) {
                    for (int k = 5; k >= 1; k--) {
                        if (isValid(i, j, k)) {
                            add(i, j, k);
                            go(i, j + k, cnt + 1);
                            delete(i, j, k);
                        }
                    }
                    return;
                }
            }
            y = 0;
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        go(0, 0, 0);
        if (ans == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(ans);
    }

}