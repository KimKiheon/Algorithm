#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool check[205]; //�湮���� üũ �迭
queue<int>q;
int n;
void bfs(int n, vector<vector<int>>computers) {
	while (!q.empty()) { //bfs�ڵ�
		int now = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			int next = i;
			if (!check[next] && computers[now][next]) { 
				//next�� �湮���� �ʾҰ�, now�� next�� ����Ǿ� �ִٸ�
				check[next] = 1;
				q.push(next);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!check[i]) { //i���� �湮���� �ʾҴٸ�
			answer++; 
			check[i] = 1; //�湮üũ
			q.push(i); //q�� �ְ� bfs ����
			bfs(n, computers);
		}
	}
	return answer;
}