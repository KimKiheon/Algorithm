#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string board[50];
int WB_cnt(int x, int y){
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != WB[i][j])cnt++;
        }
    }
    return cnt;
}
int BW_cnt(int x, int y){
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != BW[i][j])cnt++;
        };
    }
    return cnt;
}
int main() {
    int size[2];
    int cnt;
    int ans = 1e9;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i + 8 <= n; i++)
    {
        for (int j = 0; j + 8 <= m; j++)
        {
            int tmp;
            tmp = min(WB_cnt(i, j), BW_cnt(i, j));
            ans = min(tmp, ans);
        }
    }
    cout << ans;
    return 0;
}