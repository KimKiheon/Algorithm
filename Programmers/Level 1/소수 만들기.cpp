#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int isPrime[3005];
int check[55];
int answer;
void go(vector<int>nums, int cnt, int sum, int idx) {
	if (cnt == 3) {
		if (isPrime[sum]) {
			answer++;
		}
		return;
	}
	for (int i = idx; i < nums.size(); i++) {
		if (!check[i]) {
			check[i] = 1;
			go(nums, cnt + 1, sum + nums[i], i+1);
			check[i] = 0;
		}
	}
}
void prime() {
	for (int i = 2; i <= 3000; i++) isPrime[i] = i;
	for (int i = 2; i <= 3000; i++) {
		if (!isPrime[i])continue;
		for (int j = 2 * i; j <= 3000; j += i)isPrime[j] = 0;
	}
}
int solution(vector<int> nums) {
	sort(nums.begin(), nums.end());
	prime();
	go(nums, 0, 0, 0);
	return answer;
}
/*
3중 반복문으로 해결할 수 있지만, brute force 알고리즘을 복기하기 위하여
완전탐색 사용하여 해결!
*/