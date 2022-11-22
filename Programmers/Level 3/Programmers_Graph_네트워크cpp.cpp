#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool check[205]; //방문여부 체크 배열
queue<int>q;
int n;
void bfs(int n, vector<vector<int>>computers) {
	while (!q.empty()) { //bfs코드
		int now = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			int next = i;
			if (!check[next] && computers[now][next]) { 
				//next를 방문하지 않았고, now와 next가 연결되어 있다면
				check[next] = 1;
				q.push(next);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!check[i]) { //i번을 방문하지 않았다면
			answer++; 
			check[i] = 1; //방문체크
			q.push(i); //q에 넣고 bfs 시작
			bfs(n, computers);
		}
	}
	return answer;
}