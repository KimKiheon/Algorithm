#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int parent[1000005], n, m;
int f(int x) {
	if (parent[x] == x)return x;
	parent[x] = f(parent[x]);
	return parent[x];
}
void merge(int x, int y) {
	x = f(x);
	y = f(y);
	if (x == y)return;
	parent[y] = x;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			merge(b, c);
		}
		else if (a == 1) {
			if (f(b) == f(c))printf("YES\n");
			else printf("NO\n");
		}
	}
}