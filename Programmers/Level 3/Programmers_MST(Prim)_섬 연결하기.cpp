#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int, int>p;
vector<vector<int>> costs;
vector<vector<p>>v;
priority_queue<p, vector<p>, greater<p>> pq; //오름차순 우선순위 큐 선언
int answer;
bool check[105];

void prim(int start) {
	pq.push({ 0,start }); //시작점 start는 뭐든 상관 X
	while (!pq.empty()) {
		p tmp = pq.top();
		int now = tmp.second, cost = tmp.first;
		pq.pop();
		if (check[now])continue;
		answer += cost;
		check[now] = 1;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].second;
			int ncost = v[now][i].first;
			if (!check[next])pq.push({ ncost, next });
		}
	}
}


int solution(int n, vector<vector<int>> costs) {
	v.resize(n);
	for (int i = 0; i < costs.size(); i++) {//주어진 간선으로 그래프 구성
		int from = costs[i][0], to = costs[i][1], cost = costs[i][2];
		v[from].push_back({ cost,to });
		v[to].push_back({ cost,from });
	}

	prim(0); //프림 알고리즘 시작
	return answer;
}

/*
int main() {
	int n;
	cin >> n;
	v.resize(n);
	costs.resize(5);
	costs[0] = { 0,1,1 };
	costs[1] = { 0,2,2 };
	costs[2] = { 1,2,5 };
	costs[3] = { 1,3,1 };
	costs[4] = { 2,3,8 };
	for (int i = 0; i < costs.size(); i++) {
		int from = costs[i][0], to = costs[i][1], cost = costs[i][2];
		v[from].push_back({ cost,to });
		v[to].push_back({ cost,from });
	}
	prim(0);
	cout << ans;
	return 0;
}*/