#include <iostream>
#include <vector>
using namespace std;

int map[19][19];

// (왼쪽,오른쪽),(위,아래),(좌하단/우상단),(우하단,좌상단) 
vector<int> dx[] = { {0,0},{-1,1},{-1,1},{1,-1} };
vector<int> dy[] = { {-1,1},{0,0},{1,-1},{1,-1} };


// 그래프 탐색하여 오목을 찾는 함수
int search(int x, int y, int dir1, int dir2, int count) {
    if (count > 5) return 999; // 바둑알이 5개가 넘으면 더 이상 탐색 X

    // 정해진 방향으로만 움직임
    int nx = x + dx[dir1][dir2];
    int ny = y + dy[dir1][dir2];
    if (nx < 0 || ny < 0 || nx >= 19 || ny >= 19) return count;
    // 그 방향에 같은 색 돌이 있을 때만 재귀함수 호출
    // 바둑알 갯수 + 1
    if (map[nx][ny] == map[x][y]) count = search(nx, ny, dir1, dir2, count + 1);

    // 지금까지 카운트했던 바둑알 갯수 반환
    return count;
}

// 그래프 탐색 전에 방향을 정해주는 컨트롤타워
// 그래프 탐색의 결과를 합쳐 오목을 판단
int startSetting(int x, int y) {
    int ans = 0;

    //8방위로 모두 호출
    for (int i = 0; i < 4; i++) {
        int val = 1; // 집합이 다르면 다른 직선으로 보고 초기화
        for (int j = 0; j < 2; j++) {
            int nx = x + dx[i][j];
            int ny = y + dy[i][j];
            if (nx < 0 || ny < 0 || nx >= 19 || ny >= 19) continue;
            // 같은 그룹에 있는 양방향으로 search 함수 호출
            if (map[x][y] == map[nx][ny]) val += search(nx, ny, i, j, 1);
        }
        // 바둑알이 5개 일때만 
        if (val == 5) {
            ans = map[x][y]; // 해당 바둑알의 색깔 반환
            break;
        }
    }
    return ans;
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int ans, ansX, ansY;
    ans = 0;
    ansX = ansY = 99;
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> map[i][j];

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (map[i][j] != 0) {
                int val = startSetting(i, j);
                if (val != 0) {
                    // 가장 왼쪽에 있는 바둑알로 갱신해주기 위함
                    // 가장 위에 있는 바둑알은 어차피 위에서부터 탐색해서
                    // 따로 처리안해줘도 됨
                    if (j < ansY) {
                        ans = val;
                        ansX = i;
                        ansY = j;
                    }
                }
            }
        }
    }
    if (ans) {
        cout << ans << "\n";
        cout << ansX + 1 << " " << ansY + 1;
    }
    else cout << "0";
}