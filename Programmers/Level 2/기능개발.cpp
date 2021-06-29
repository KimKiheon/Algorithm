#include <string>
#include <vector>

using namespace std;
int check[105];
vector<int> solution(vector<int> pro, vector<int> speed) {
	vector<int> ans;
	int cur = 0, flag = 0;
	while (cur < pro.size()) {
		for (int i = cur; i < pro.size(); i++) {
			if (pro[i] >= 100)continue;
			pro[i] += speed[i];
		}
		for (int i = cur; i < pro.size(); i++) {
			if (pro[i] < 100)break;
			flag = i + 1;
		}
		if (flag != cur) {
			ans.push_back(flag - cur);
			cur = flag;
		}
	}
	return ans;
}