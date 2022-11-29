#include<string>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;
typedef pair<int, bool>p;
int solution(vector<int> priorities, int location) {
	deque<p>q;
	int answer = 1;
	for (int i = 0; i < priorities.size(); i++)	q.push_back({ priorities[i],false });

	q[location].second = true;
	sort(priorities.begin(), priorities.end());

	while (1) {
		if (q.front().first == priorities.back()) {
			if (q.front().second)return answer;
			q.pop_front();
			priorities.pop_back();
			answer++;
			continue;
		}
		p tmp = q.front();
		q.pop_front();
		q.push_back(tmp);
	}
}