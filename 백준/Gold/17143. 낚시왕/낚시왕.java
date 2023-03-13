import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Shark {
        int x, y, speed, d, size;
        boolean live = true;

        public Shark(int x, int y, int speed, int d, int size) {
            this.x = x;
            this.y = y;
            this.speed = speed;
            this.d = d;
            this.size = size;
        }
    }

    static int r, c, n, now, ans;
    static int arr[][];
    static int[] dx = {0, -1, 1, 0, 0}, dy = {0, 0, 0, 1, -1};
    static Shark[] sharks;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        sharks = new Shark[n + 1];
        sharks[0] = null;
        arr = new int[r + 1][c + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            Shark tmp = new Shark(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()));
            sharks[i] = tmp;
            arr[tmp.x][tmp.y] = i;
            if (tmp.d <= 2) tmp.speed = tmp.speed % ((r - 1) * 2);
            else tmp.speed = tmp.speed % ((c - 1) * 2);
        }
    }

    static int kill() {
        int size = 0;
        for (int i = 1; i <= r; i++) {
            int num = arr[i][now];
            if (num > 0) {
                size = sharks[num].size;
                sharks[num].live = false;
                arr[i][now] = 0;
                return size;
            }
        }
        return 0;
    }

    static void move() {
        for (int i = 1; i <= n; i++) {
            Shark s = sharks[i];
            if (!s.live) continue;
            if(arr[s.x][s.y]==i) arr[s.x][s.y]= 0;
            for (int j = 0; j < s.speed; j++) {
                s.x += dx[s.d];
                s.y += dy[s.d];
                if (s.x < 1 || s.x > r || s.y < 1 || s.y > c) {
                    if (s.d == 1 || s.d == 3) s.d++;
                    else s.d--;
                    s.x += dx[s.d];
                    s.y += dy[s.d];
                    j--;
                }
            }
            if (arr[s.x][s.y] == 0) arr[s.x][s.y] = i;
            else if (arr[s.x][s.y] < i) {
                Shark tmp = sharks[arr[s.x][s.y]];
                if (s.size > tmp.size) {
                    sharks[arr[s.x][s.y]].live = false;
                    arr[s.x][s.y] = i;
                } else {
                    s.live = false;
                }
            } else arr[s.x][s.y] = i;
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        for (int i = 1; i <= c; i++) {
            now = i;
            ans += kill();
            move();
        }
        System.out.println(ans);
    }
}