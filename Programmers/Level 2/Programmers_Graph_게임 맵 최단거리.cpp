#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int>p;
queue<p>q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int check[105][105];

int solution(vector<vector<int> > maps)
{
    int answer;
    q.push({ 0,0 });
    check[0][0] = 1;
    while (!q.empty()) {
        p now = q.front();
        q.pop();
        int x = now.first, y = now.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || maps.size() <= nx || ny < 0 || maps[0].size() <= ny || !maps[nx][ny])continue;
            if (!check[nx][ny]) {
                check[nx][ny] = check[x][y] + 1;
                q.push({ nx,ny });
            }
        }
    }
    answer = check[maps.size() - 1][maps[0].size() - 1];
    return !answer ? -1 : answer;
}