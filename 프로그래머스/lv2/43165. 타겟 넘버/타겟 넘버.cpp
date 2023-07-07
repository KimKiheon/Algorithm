#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dfs(vector<int> numbers, int target, int now, int plus, int sum) {
    if (now == numbers.size()-1) {
        sum += numbers[now] * plus;
       // cout << sum << "\n";
        if (sum != target) return 0;
        return 1;
    }
    
    return dfs(numbers, target, now + 1, 1, sum + numbers[now] * plus)
        + dfs(numbers, target, now + 1, -1, sum + numbers[now] * plus);
}
int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 1, 0) + dfs(numbers, target, 0 , -1, 0);
}