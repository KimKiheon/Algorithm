#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int answer = 0;
    for (int i = citations.size() - 1; i >= 0; i--) {
        if (citations[i] <= answer)break;
        answer++;
    }
    return answer;
}