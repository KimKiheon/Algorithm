#include<vector>
using namespace std;
int arr[200005];
int solution(vector<int> nums)
{
    int answer = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (!arr[nums[i]]) answer++;
        arr[nums[i]]++;
    }
    if (answer >= (nums.size() / 2)) answer = nums.size() / 2;
    return answer;
}