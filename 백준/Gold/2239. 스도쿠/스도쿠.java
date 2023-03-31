import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static boolean row[][], col[][], zone[][];
    static int arr[][];

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        row = new boolean[9][10];
        col = new boolean[9][10];
        zone = new boolean[9][10];
        arr = new int[9][9];
        for (int i = 0; i < 9; i++) {
            String[] tmp = br.readLine().split("");
            for (int j = 0; j < 9; j++) {
                arr[i][j] = Integer.parseInt(tmp[j]);
                if (arr[i][j] > 0) {
                    int x = arr[i][j];
                    row[i][x] = col[j][x] = zone[3 * (i / 3) + j / 3][x] = true;
                }
            }
        }
    }

    static void print() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(arr[i][j]);
            }
            System.out.println();
        }
    }

    static void go(int cnt) {
        int x = cnt / 9, y = cnt % 9;
        int tmp = 3 * (x / 3) + (y / 3);
        if (cnt == 81) {
            print();
            System.exit(0);
        }
        if(arr[x][y]==0) {
            for (int i = 1; i <= 9; i++) {
                if (row[x][i] == true || col[y][i] == true || zone[tmp][i] == true) continue;
                row[x][i] = col[y][i] = zone[tmp][i] = true;
                arr[x][y] = i;
                go(cnt + 1);
                row[x][i] = col[y][i] = zone[tmp][i] = false;
                arr[x][y] = 0;
            }
        }
        else if (arr[x][y] != 0) go(cnt + 1);
    }

    public static void main(String[] args) throws IOException {
        input();
        go(0);
    }
}