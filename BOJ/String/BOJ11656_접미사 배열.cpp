#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string s;
	vector<string>v;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		string ss = s.substr(i);
		v.push_back(ss);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)cout << v[i] << "\n";
	return 0;
}