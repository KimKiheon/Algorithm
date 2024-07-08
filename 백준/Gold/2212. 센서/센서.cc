#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
vector<int> v;
vector<int> v2;
int main(void)
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 1; i++)
		v2.push_back(v[i + 1] - v[i]);

	sort(v2.begin(), v2.end());

	int ans = 0;
	for (int i = 0; i < v2.size() - (K - 1)&&!v2.empty(); i++)
		ans += v2[i];
	cout << ans;
}