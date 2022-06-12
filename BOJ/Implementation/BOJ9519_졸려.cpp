#include<iostream>
#include<string>
using namespace std;
string str, str2;
int n, cnt;
bool check;
string go(int l) {
	string temp;
	if (l % 2) {
		for (int i = 0; i < l; i += 2)temp += str[i];
		for (int i = l - 2; i >= 1; i -= 2)temp += str[i];
	}
	else {
		for (int i = 0; i < l; i += 2)temp += str[i];
		for (int i = l - 1; i >= 1; i -= 2)temp += str[i];
	}
	return temp;
}
int main() {
	cin >> n;
	cin >> str;
	str2 = str;
	int len = str.length();
	for (int i = 0; i < n; i++) {
		str = go(len);
		cnt++;
		if (str == str2) {
			n %= cnt;
			check = true;
			break;
		}
	}
	if (!check) {
		cout << str;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		str = go(len);
	}
	cout << str;
	return 0;
}