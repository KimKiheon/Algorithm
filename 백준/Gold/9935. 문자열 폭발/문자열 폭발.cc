#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<utility>
#include<deque>
using namespace std;
string str, del;
deque<char>dq;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> str >> del;
	int len = del.size();
	for (int i = 0; i < str.size(); i++) {
		dq.push_back(str[i]);
		if (str[i] == del[len - 1] && dq.size() > len - 1) {
			string tmp;
			for (int j = 0; j < len; j++) 	tmp += dq.back(), dq.pop_back();
			reverse(tmp.begin(), tmp.end());
			if (tmp == del)continue;
			for (int j = 0; j < tmp.size(); j++) dq.push_back(tmp[j]);
		}
	}
	if (dq.empty()) {
		cout << "FRULA" << "\n";
		return 0;
	}
	while (!dq.empty())cout << dq.front(), dq.pop_front();
	cout << "\n";
	return 0;
}