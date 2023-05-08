import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Pos {
	int x, y, d = 0; // d-> 0: 세로, d->1: 가로
	int cnt = 0;

	public Pos(int x, int y) {
		this.x = x;
		this.y = y;
	}


	public Pos(int x, int y, int d, int cnt) {
		super();
		this.x = x;
		this.y = y;
		this.d = d;
		this.cnt = cnt;
	}

	@Override
	public String toString() {
		return "Pos [x=" + x + ", y=" + y + ", d=" + d + ", cnt=" + cnt + "]";
	}

}

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int n, dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 }; //4방탐색
	static int tx[] = { 0, 0, -1, -1, -1, 1, 1, 1 }, ty[] = { -1, 1, -1, 0, 1, -1, 0, 1 }; //8방탐색
	static char arr[][]; //입력 배열
	static Queue<Pos> q = new LinkedList<>();
	static boolean check[][][]; // x, y, d //좌표, 방향을 포함한 visited 체크
	static Pos start, end; //  //시작점 끝점

	static boolean isValid(int x, int y) {
		return !(x < 0 || x > n - 1 || y < 0 || y > n - 1); //인덱스 범위 체크
	}

	static boolean canMove(int x, int y, int d) { // 움직일 수 있는지, param: 기둥의 다음 중심좌표
		if (d == 0) {//기둥이 세로방향일 때
			return isValid(x - 1, y) && isValid(x + 1, y) && arr[x - 1][y] != '1' && arr[x + 1][y] != '1'; //중심으로부터 +1, -1 칸이 유효 범위이고 1이 아닌지 검사
		} else {//기둥이 가로방향일 때
			return isValid(x, y - 1) && isValid(x, y + 1) && arr[x][y - 1] != '1' && arr[x][y + 1] != '1'; //중심으로부터 +1, -1 칸이 유효 범위이고 1이 아닌지 검사
		}
	}

	static boolean canTurn(int x, int y) {
		for (int i = 0; i < 8; i++) { //8방 탐색
			int nx = x + tx[i], ny = y + ty[i];
			if (!isValid(nx, ny) || arr[nx][ny] == '1') //중심좌표로부터 8방향이 모두 유호범위이고 1이 없는지 검사
				return false;
		}
		return true;
	}

	static void input() throws Exception, IOException { //입력
		n = Integer.parseInt(br.readLine());
		arr = new char[n][n];
		check = new boolean[n][n][2];
		int b = 0, e = 0;
		Pos b1, e1;
		b1 = new Pos(0, 0);
		e1 = new Pos(0, 0);
		for (int i = 0; i < n; i++) {
			arr[i] = br.readLine().toCharArray();
			for (int j = 0; j < arr[i].length; j++) {
				if (arr[i][j] == 'B') { // B일때
					b++;
					if (b == 2) { //2번째 B이면 1번째 B와 비교해서 방향이 가로인지 세로인지
						start = new Pos(i, j);
						if (isValid(i - 1, j) && b1.x == i - 1 && b1.y == j) {
							start.d = 0;
						} else {
							start.d = 1;
						}
					}
					b1.x = i;
					b1.y = j;
					arr[i][j] = '0'; //B -> 0으로 변경

				} else if (arr[i][j] == 'E') { //E일때
					e++;
					if (e == 2) { //2번째 E이면 1번째 E와 비교해서 방향이 가로인지 세로인지
						end = new Pos(i, j);
						if (isValid(i - 1, j) && e1.x == i - 1 && e1.y == j) {
							end.d = 0;
						} else {
							end.d = 1;
						}
					}
					e1.x = i;
					e1.y = j;
					arr[i][j] = '0'; //E -> 0으로 변경
				}
			}
		}
	}

	static void bfs() {
		q.add(start);
		check[start.x][start.y][start.d] = true;
		while (!q.isEmpty()) {
			int x = q.peek().x, y = q.peek().y, cnt = q.peek().cnt, d = q.poll().d;
			if (x == end.x && y == end.y && d == end.d) { //end값 만났을 때
				System.out.println(cnt);
				System.exit(0);
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!isValid(nx, ny) || !canMove(nx, ny, d) || (check[nx][ny][d])||arr[nx][ny]=='1')
					//nx, ny가 유효범위이고 움직일 수 있고, 방문한 적이 없고, 1이 아닐 때
					continue;
				q.add(new Pos(nx, ny, d, cnt + 1));
				check[nx][ny][d] = true;
			}
			if (!check[x][y][1 - d] && canTurn(x, y)) { //중복검사 및 회전할 수 있는지 검사
				q.add(new Pos(x, y, 1 - d, cnt + 1));
				check[x][y][1 - d] = true;
			}
		}
		System.out.println(0);
	}

	public static void main(String[] args) throws Exception {
		input();
		bfs();
	}
}