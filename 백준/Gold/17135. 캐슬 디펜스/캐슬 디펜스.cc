#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int>p;
typedef pair<pair<int, int>, int>pp;
int n, m, d;
int firstboard[16][16];
int board[16][16];
int ret;
bool check(){
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j] == 1)
				return false;
	return true;
}

bool compare(pp a, pp b){
	if (a.second == b.second)	return a.first.second < b.first.second;
	else	return a.second < b.second;
}
void whereToAttack(vector<pair<int, int>>& pos, int y, int x){
	vector<pp> temp;
	for (int i = y - 1; i >= 0; --i){
		for (int j = 0; j < m; ++j){
			int dis = abs(y - i) + abs(x - j);
			if (dis > d) continue;

			if (board[i][j] == 1)	temp.push_back({ { i,j },dis });
		}
	}

	sort(temp.begin(), temp.end(), compare);
	if (temp.size() >= 1)	pos.push_back({ temp[0].first.first, temp[0].first.second });

}
int findtheMax() {
	int ans = 0;
	while (1) {
		if (check())	break;

		vector<pair<int, int>> pos;

		for (int i = 0; i < m; ++i) {
			if (board[n][i] == 2)	{
				whereToAttack(pos, n, i);
			}
		}

		for (int i = 0; i < pos.size(); ++i) {
			int y = pos[i].first;
			int x = pos[i].second;
			if (board[y][x] != 0)	{
				board[y][x] = 0;
				ans++;
			}
		}

		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 1) {

					if (i == n - 1) board[i][j] = 0;
					else {
						board[i + 1][j] = 1;
						board[i][j] = 0;
					}
				}
			}
		}
	}
	return ans;
}
void ArrowPosition(int begin, vector<int>& picked){
	if (picked.size() == 3){
		for (int i = 0; i < picked.size(); ++i)	board[n][picked[i]] = 2;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				board[i][j] = firstboard[i][j];

		ret = max(ret, findtheMax());

		for (int i = 0; i < picked.size(); ++i)	board[n][picked[i]] = 0;
		return;
	}
	for (int i = begin + 1; i < m; ++i) {
		picked.push_back(i);
		ArrowPosition(i, picked);
		picked.pop_back();
	}
}
int main(){
	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> firstboard[i][j];

	vector<int> picked;
	ArrowPosition(-1, picked);

	cout << ret << "\n";
	return 0;
}