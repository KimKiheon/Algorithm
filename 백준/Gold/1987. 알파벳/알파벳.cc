#include<iostream>
#include<algorithm>
int dy[4]={ 1,-1,0,0 };
int dx[4]={ 0,0,1,-1 };
int visited[26],R,C,ans;
char arr[20][20];
using namespace std;
void dfs(int y, int x, int cnt) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (xx < 0 || xx >= C || yy < 0|| yy >= R)continue;
		int tmp = (int)arr[yy][xx] - 65;
		if (visited[tmp])continue;
		visited[tmp]++;
		dfs(yy, xx, cnt+1);
		visited[tmp]--;
	}
}
int main(void) {

	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf(" %c", &arr[i][j]);
	visited[(int)arr[0][0]-65]++;
	dfs(0, 0, 1);
	printf("%d", ans);
	return 0;
}