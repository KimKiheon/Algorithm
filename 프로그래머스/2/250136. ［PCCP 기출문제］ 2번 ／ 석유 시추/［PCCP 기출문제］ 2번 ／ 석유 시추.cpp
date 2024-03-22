#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

typedef pair<int,int>p;
queue<p>q;
int n, m;
int visited[505][505];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool isValid(int x, int y){
    return !(x < 0  ||x > n-1 || y < 0 || y > m-1);
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int num = 0;
    vector<int> landSize;
    n = land.size();
    m = land[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]||!land[i][j]) continue;
            int cnt = 1;
            q.push({i,j});
            visited[i][j] = ++num;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(!isValid(nx,ny)||visited[nx][ny]||!land[nx][ny]) continue;
                    q.push({nx,ny});
                    visited[nx][ny] = num;
                    cnt++;
                }
                
            }
            landSize.push_back(cnt);
        }
    }
    for(int i=0;i<m;i++){
        set<int> tmp;
        int sum = 0;
        for(int j=0;j<n;j++){
            if(land[j][i]){
                tmp.insert(visited[j][i]);
            }
        }
        for (auto it = tmp.begin(); it != tmp.end(); ++it) {
            sum+=landSize[(*it)-1];
        };
        answer = max(answer, sum);

    }
    return answer;
}