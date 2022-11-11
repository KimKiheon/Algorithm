#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main() {
	int n;
	int arr1[16];
	int arr2[16];
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr1[i];
	for (int i = 0; i < n; i++)cin >> arr2[i];
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		arr1[i] = arr1[i] | arr2[i];
	}
	for (int i = 0; i < n; i++) {
		string str;
		for (int j = n - 1; j >= 0; j--) {
			if ((arr1[i] >> j & 1))str += '#';
			else str += " ";
		}
		answer.push_back(str);
	}

	for (int i = 0; i < answer.size(); i++)cout << answer[i] << "\n";
	return 0;
}