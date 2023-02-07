#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
using namespace std;
typedef pair<pair<int, int>, string> p;
vector<p>v;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		string s;
		cin >> a >> s;
		v.push_back({ {a,i},s });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first.first << " " << v[i].second<<"\n";
	}
	return 0;
}