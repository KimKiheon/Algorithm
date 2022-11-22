#include<string>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>>v;
queue<int>q;
int maxi, answer;
int dist[20005];
void bfs() { //bfs 시작

	while (!q.empty()) { //q가 빌 때 까지
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {//now에서 연결된 노드들 방문하기 
			int next = v[now][i]; 
			if (!dist[next]) { //next가 방문처리 안되어 있다면
				dist[next] = dist[now] + 1; //now보다 1칸 멀리 있으므로 dist[now] + 1
				q.push(next);
				maxi = max(maxi, dist[next]); //방문처리 하면서 1번 노드로부터 제일 멀리있는값 계속 갱신
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	v.resize(n + 1);
	for (int i = 0; i < edge.size(); i++) { //간선의 정보를 사용하여 리스트를 이용한 그래프 만들기
		for (int j = 0; j < 2; j++) {
			int a = edge[i][0], b = edge[i][1];
			v[a].push_back(b); //양방향 그래프이기 때문에 양쪽 연결
			v[b].push_back(a);
		}
	}

	dist[1] = 1; //시작점이 1번이기에 방문체크 
	q.push(1);

	bfs();

	for (int i = 1; i <= n; i++) if (dist[i] == maxi) answer++; //최대거리에 있는 노드 개수 찾기
	return answer;
}