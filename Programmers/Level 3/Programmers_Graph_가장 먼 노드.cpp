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
void bfs() { //bfs ����

	while (!q.empty()) { //q�� �� �� ����
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {//now���� ����� ���� �湮�ϱ� 
			int next = v[now][i]; 
			if (!dist[next]) { //next�� �湮ó�� �ȵǾ� �ִٸ�
				dist[next] = dist[now] + 1; //now���� 1ĭ �ָ� �����Ƿ� dist[now] + 1
				q.push(next);
				maxi = max(maxi, dist[next]); //�湮ó�� �ϸ鼭 1�� ���κ��� ���� �ָ��ִ°� ��� ����
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	v.resize(n + 1);
	for (int i = 0; i < edge.size(); i++) { //������ ������ ����Ͽ� ����Ʈ�� �̿��� �׷��� �����
		for (int j = 0; j < 2; j++) {
			int a = edge[i][0], b = edge[i][1];
			v[a].push_back(b); //����� �׷����̱� ������ ���� ����
			v[b].push_back(a);
		}
	}

	dist[1] = 1; //�������� 1���̱⿡ �湮üũ 
	q.push(1);

	bfs();

	for (int i = 1; i <= n; i++) if (dist[i] == maxi) answer++; //�ִ�Ÿ��� �ִ� ��� ���� ã��
	return answer;
}