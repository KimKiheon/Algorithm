#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;
int t, n, ans;
string str;
bool check[27];
vector<vector<char>>v;
void go(char a,int cnt) {
	if (cnt == n) {
		int temp = 0;
		for (int i = 0; i < t; i++) {
			bool flag = true;
			for (int j = 0; j < v[i].size(); j++) {
				if (!check[v[i][j]-'a']) {
					flag = false;
					break;
				}
			}
			
			if (flag)temp++;
		}
		ans = max(ans, temp);
		return;
	}
	for (char x = a; x <= 'z'; x++) {
		if (!check[x - 97]) {
			check[x - 97] = true;
			go(x, cnt + 1);
			check[x - 97] = false;
		}
	}
}
int main() {
	scanf("%d %d ", &t, &n);
	v.resize(t);
	check['a' - 97] = check['n' - 97] = check['t' - 97] = check['i' - 97] = check['c' - 97] = true;
	for (int i = 0; i < t; i++) {
		cin >> str;
		for (int j = 4; j < str.length()-4; j++) {
			v[i].push_back(str[j]);
		}
	}
	if (n < 5) {
		printf("0");
		return 0;
	}
	else if (n == 26) {
		printf("%d", t);
		return 0;
	}
	n -= 5;
	go('a', 0);
	printf("%d", ans);
	return 0;
}