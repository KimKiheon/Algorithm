#include<iostream>
#include<string>
#include<cstring>
#include<deque>
using namespace std;
int check[26];
int dna[4] = { 0,2,6,19 };
int n, m, ans;
string str;
deque<char>sb;
bool checkDna() {
	for (int i = 0; i < 4; i++)	if (check[dna[i]] > 0)	return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> str;
	for (int i = 0; i < 4; i++)cin >> check[dna[i]];
	for (int i = 0; i < m; i++) {
		char c = str[i];
		check[c - 'A']--;
		sb.push_back(str[i]);
	}
	if (checkDna())ans++;
	for (int i = m; i < n; i++) {
		check[sb[0] - 'A']++;
		sb.pop_front();
		sb.push_back(str[i]);
		check[str[i] - 'A']--;
		if (checkDna())ans++;
	}
	cout << ans << "\n";
	return 0;
}