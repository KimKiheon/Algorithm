import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Pos {
        int x, y;
        boolean check = false;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int t, n;
    static Pos home, des, mart[];
    static boolean check[];
    static Queue<Pos> q;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        q = new ArrayDeque<>();
        mart = new Pos[n + 2];
        home = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        mart[0] = home;
        for (int i = 1; i < n+1; i++) {
            st = new StringTokenizer(br.readLine());
            mart[i] = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(br.readLine());
        des = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        mart[n+1] = des;
    }

    static boolean bfs() {
        q.add(home);
        while (!q.isEmpty()) {
            int x = q.peek().x, y = q.poll().y;
            for (int i=0;i< mart.length;i++) {
                int nx = mart[i].x, ny = mart[i].y;
                int dist = Math.abs(nx - x) + Math.abs(ny - y);
                if (dist > 1000 || mart[i].check) continue;
                if (nx == des.x && ny == des.y) return true;
                q.add(new Pos(nx, ny));
                mart[i].check = true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            input();
            if (bfs()) System.out.println("happy");
            else System.out.println("sad");
        }
    }
}