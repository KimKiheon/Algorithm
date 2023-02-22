#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int dist[22][22][10];
bool check[22][22][10];
char map[22][22];
typedef pair<int, int>p;
vector<pair<p, int>> v;
int sx, sy;
void bfs(int x, int y, int pos) {
    queue<p> q;
    q.push({ x,y });
    dist[x][y][pos] = 0;
    check[x][y][pos] = 1;
    while (!q.empty()) { //거리 구하는 bfs
        x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (!check[nx][ny][pos] && map[nx][ny] != 'x') {
                    check[nx][ny][pos] = true;
                    dist[nx][ny][pos] = dist[x][y][pos] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while (1) {
        cin >> m >> n;
        if (!n && !m) break;
        for (int i = 0; i < 22; i++)   //dist배열, check, map배열 초기화, 벡터 비우기
            for (int j = 0; j < 22; j++) 
                for (int k = 0; k < 10; k++)
                    dist[i][j][k] = 1e5;
                
        memset(check, 0, sizeof(check));
        memset(map, 0, sizeof(map));
        v.clear();

        sx = sy = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                if (map[i][j] == '*') v.push_back({ { i,j }, cnt++ });
                if (map[i][j] == 'o')sx = i, sy = j;
            }
        }
        int ans = 1e5;
        int s = v.size();
        if (!s) {
            cout << 0 << "\n";
            continue;
        }
        bfs(sx, sy, 0); //첫 청소기 위치에서 bfs
        sort(v.begin(), v.end());
        for (int i = 0; i < s; i++) bfs(v[i].first.first, v[i].first.second, v[i].second); //쓰레기별로 bfs
        do {
            int temp = dist[v[0].first.first][v[0].first.second][0];
            for (int i = 0; i < s - 1; i++) temp += dist[v[i + 1].first.first][v[i + 1].first.second][v[i].second];  //순열 순서로 거리 더하기
            ans = min(ans, temp);
        } while (next_permutation(v.begin(), v.end())); //다음 순열
        if (ans == 1e5)cout << -1 << "\n";
        else cout << ans << "\n";;
    }
    return 0;
}