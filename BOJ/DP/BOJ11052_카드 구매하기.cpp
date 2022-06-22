#include<algorithm>
#include<iostream>
using namespace std;

int dp[1001] = { 0 };
int p[1001];
int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], (dp[i - j] + p[j]));
        }
    }
    cout << dp[n] << "\n";
    return 0;
}