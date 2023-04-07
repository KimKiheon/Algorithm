#include<iostream>
#include<algorithm>
using namespace std;
int n;
int inorder[100005], postorder[100005];
int arr[100005];
int index[100005];
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inorder[i];
		index[inorder[i]] = i;
	}
	for (int i = 1; i <= n; i++)cin >> postorder[i];
}
void go(int il, int ir, int pl, int pr) {
	if (il > ir || pl > pr) return;
	int idx = index[postorder[pr]];
	int left = idx - il;
	int right = ir - idx;
	cout << inorder[idx] << ' ';

	go(il, idx - 1, pl, pl+left-1);
	go(idx + 1, ir, pl + left, pr - 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	input();
	go(1, n, 1, n);
	return 0;
}