#include <iostream>
using namespace std;
int n, m, h, ans;

int map[31][11];

bool check() {
    bool flag = true;

    for (int i = 1; i <= n; i++) {
        int pos = i;
        for (int j = 0; j <= h; j++) {
            if (map[j][pos] == 1) pos++;
            else if (map[j][pos - 1] == 1)pos--;
        }
        if (pos != i) return flag = false;
    }
    return flag;
}


void dfs(int count, int x, int y) {
    if (count >= ans) return;
    if (check()) {
        ans = count;
        return;
    }
    if (count == 3) return;
    for (int i = x; i <= h; i++) {
        for (int j = y; j < n; j++) {
            if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0) { //선을 그을수 있으면 
                map[i][j] = 1;
                dfs(count + 1, i, j);
                map[i][j] = 0;
            }

        }
        y = 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    ans = 4;
    dfs(0, 1, 1);
    if (ans == 4) ans = -1;
    cout << ans;

    return 0;
}