import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M, K;
    static int[] seq; 
    static int[][] arr, arr2, cycle;
    static boolean[] check;
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken()); 

        arr = new int[N][M];
        arr2 = new int[N][M];
        cycle = new int[K][3];

        seq = new int[K];
        check = new boolean[K];

        // 배열 입력
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr2[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int k = 0; k < K; k++) {
            st = new StringTokenizer(br.readLine());
            cycle[k][0] = Integer.parseInt(st.nextToken()) - 1;
            cycle[k][1] = Integer.parseInt(st.nextToken()) - 1;
            cycle[k][2] = Integer.parseInt(st.nextToken());
        }

        combination(0);
        System.out.println(ans);
        br.close();
    }

    public static int get_min_val() {
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) sum += arr[i][j];
            res = Math.min(res, sum);
        }
        return res;
    }

    static void rotate(int r, int c, int s) {
        int x1 = r - s, y1 = c - s;
        int x2 = r + s, y2 = c + s;

        while (true) { 
            if (x1 >= x2) break;
            int tmp = arr[x1][y1];
            for (int i = x1; i < x2; i++) arr[i][y1] = arr[i + 1][y1];
            for (int j = y1; j < y2; j++) arr[x2][j] = arr[x2][j + 1];
            for (int i = x2; i > x1; i--) arr[i][y2] = arr[i - 1][y2];
            for (int j = y2; j > y1; j--) arr[x1][j] = arr[x1][j - 1];
            arr[x1][y1 + 1] = tmp;
            x1++;
            y1++;
            x2--;
            y2--;
        }
    }

    static void combination(int cnt) {
        if (cnt == K) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) arr[i][j] = arr2[i][j];
            }
            for (int i = 0; i < K; i++) {
                int s = seq[i];
                rotate(cycle[s][0], cycle[s][1], cycle[s][2]);
            }
            ans = Math.min(ans, get_min_val());
            return;
        }

        for (int k = 0; k < K; k++) {
            if (check[k]) continue;
            check[k] = true;
            seq[cnt] = k;
            combination(cnt + 1); 
            check[k] = false; 
        }
    }
}