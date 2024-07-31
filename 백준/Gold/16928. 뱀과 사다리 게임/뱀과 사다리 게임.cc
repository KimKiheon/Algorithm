#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
int map[101]= {0,};
int visited[101];


void bfs(int sx){
    queue<int> q;
    visited[sx] = 0;
    q.push(sx);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x > 100) continue;
        for(int i = 1; i <= 6; i++){
            int nx;
            if(x+i <= 100 && map[x+i]) nx = map[x+i]; 
            else nx = x+i; 

            if(visited[nx] > visited[x]+1){
                visited[nx] = visited[x]+1;
                q.push(nx);
            }
        }
    }
}


int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int v1, v2;
        cin >> v1 >> v2;
        map[v1] = v2;
    }
    for(int i = 0; i < M; i++){
        int v1, v2;
        cin >> v1 >> v2;
        map[v1] = v2;
    }

    for(int i = 0; i <= 100; i++) visited[i] = 9999;
    bfs(1);

    cout << visited[100];
}