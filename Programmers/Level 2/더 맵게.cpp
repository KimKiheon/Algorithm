#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int solution(vector<int > scoville, int K) {
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while (1) {
        ll tmp = 0;
        if (pq.top() >= K) break;
        if (pq.size() == 1) return -1;
        tmp += pq.top();
        pq.pop();
        tmp += pow(pq.top(), 2);
        pq.pop();
        pq.push(tmp);
        answer++;
    }
    return answer;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << solution(v, k);
    return 0;
}