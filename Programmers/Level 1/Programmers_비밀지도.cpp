#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		arr1[i] = arr1[i] | arr2[i]; //OR연산
	}
	for (int i = 0; i < n; i++) {
		string str;
		for (int j = n - 1; j >= 0; j--) {
			if ((arr1[i] >> j & 1))str += '#'; //2진법으로 변환후 1일경우 string에 # 추가
			else str += " ";//0일경우 공백 추가
		}
		answer.push_back(str); //리스트에 str 추가
	}
	return answer;
}