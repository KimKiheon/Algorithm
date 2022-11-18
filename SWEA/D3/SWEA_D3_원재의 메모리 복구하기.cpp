#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		string str;
		cin >> str;
		int cnt = 1;
		for (int i = 0; i < str.size() - 1; i++) {
			if (str[i] != str[i + 1])cnt++;
		}
		if (str[0] == '0')cnt--;
		cout << '#' << T << " " << cnt << "\n";
	}
	return 0;
}