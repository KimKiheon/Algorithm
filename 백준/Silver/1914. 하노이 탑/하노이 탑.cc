#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int N;

void go(int n, int start, int by, int to) {
	if (n == 1) {
		cout << start <<" "<< to << "\n";
		return;
	}
	go(n - 1, start, to, by);
	cout << start << " "<<to << "\n";
	go(n - 1, by, start, to);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> N;
	string str = to_string(pow(2, N));
	str = str.substr(0, str.find('.'));
	str[str.size() - 1]--;
	cout << str << "\n";
	if (N <= 20)go(N, 1, 2, 3);
	return 0;
}