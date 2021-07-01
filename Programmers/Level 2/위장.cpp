#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cnt[35];
int solution(vector<vector<string>> clothes) {
    int answer = 0, count = 1, tmp = 1;
    vector<string> v;
    for (int i = 0; i < clothes.size(); i++)
        v.push_back(clothes[i][1]);
    sort(v.begin(), v.end());
    cnt[0]++;
    for (int i = 1; i < v.size(); i++) {
        if(v[i]!=v[i-1]) count++;
        cnt[count-1]++;
    }
    for (int i = 0; i < count; i++) tmp = tmp * (cnt[i] + 1);
    answer = tmp - 1;
    return answer;
}