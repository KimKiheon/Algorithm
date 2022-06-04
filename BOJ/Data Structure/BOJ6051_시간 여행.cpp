#include<vector>
#include<iostream>
using namespace std;
vector<vector<int>>dp;
char x;
int y, t, i = 1;
void dpLoad(int size) {
    for (int j = 0; j < size; j++) {
        dp[i].push_back(dp[i - 1][j]);
    }
}
int main() {
    dp.resize(80001);
    dp[0].push_back(-1);
    scanf(" %d", &t);
    while (t--) {
        scanf(" %c", &x);
        if (x == 'a') {
            scanf(" %d", &y);
            if (i != 1) {
                dpLoad(dp[i - 1].size());
                dp[i].push_back(y);
            }
            else {
                dp[i].push_back(y);
                printf("%d\n", y);
                i++;
                continue;
            }
            printf("%d\n", dp[i].back());
        }
        else if (x == 's') {
            if (dp[i - 1].size())dpLoad(dp[i - 1].size());
            if (!dp[i].empty()) {
                dp[i].pop_back();
                if (dp[i].empty()) {
                    printf("-1\n");
                }
                else {
                    printf("%d\n", dp[i].back());
                }
            }
            else {
                printf("-1\n");
            }
        }
        else if (x == 't') {
            scanf(" %d", &y);
            for (int j = 0; j < dp[y - 1].size(); j++) {
                dp[i].push_back(dp[y - 1][j]);
            }
            if (dp[i].empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", dp[i].back());
            }
        }
        i++;
    }
    return 0;
}