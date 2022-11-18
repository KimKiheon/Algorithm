#include<iostream>
#include<string>
using namespace std;
int main() {
	int t = 10;
	while (t--) {
		int tc, ans = 0;
		bool flag;
		string str, key;
		cin >> tc;
		cin >> key >> str;
		for (int i = 0; i < str.size(); i++) {
			flag = true;
			if (str[i] == key[0]) {
				for (int j = 0; j < key.size(); j++) {
					if (str[i + j] != key[j]) {
						flag = false;
						break;
					}
				}
				if (flag)ans++;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}