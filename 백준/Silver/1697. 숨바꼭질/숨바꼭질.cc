#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int>p;
queue<p>q;
bool visited[400005];
int a, b, cnt;
void bfs(int start,int end) {
	q.push({ a,0 });
	while (!q.empty()) {
		p now = q.front();
		q.pop();
		int x = now.first;
		int temp = now.second;
		if (x == end) {
			printf("%d", temp);
			return;
		}
		if (x*2<=100000&&!visited[2 * x]) {
			visited[2 * x] = 1;
			q.push({ 2*x,temp+1 });
		}
		if (x<100000&&!visited[x + 1]) {
			visited[x + 1] = 1;
			q.push({ x + 1,temp + 1 });
		}
		if (x>0&&!visited[x - 1]) {
			visited[x - 1] = 1;
			q.push({ x - 1,temp + 1 });
		}
	}
}
int main() {
	scanf("%d %d", &a, &b);
	visited[a] = 1;
	bfs(a, b);
	return 0;
}