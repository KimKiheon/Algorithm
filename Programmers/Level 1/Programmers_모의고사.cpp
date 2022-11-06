#include <string>
#include <vector>

using namespace std;
int n1[5] = { 1,2,3,4,5 };
int n2[8] = { 2,1,2,3,2,4,2,5 };
int n3[10] = { 3,3,1,1,2,2,4,4,5,5 };
int maxi = 0;
vector<int>sum;
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	sum.resize(3);
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == n1[i % 5])sum[0]++;
		if (answers[i] == n2[i % 8])sum[1]++;
		if (answers[i] == n3[i % 10])sum[2]++;
		maxi = max(maxi, max(sum[0], max(sum[1], sum[2])));
	}
	for (int i = 0; i < 3; i++) {
		if (sum[i] == maxi)answer.push_back(i + 1);
	}
	return answer;
}