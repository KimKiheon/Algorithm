#include<iostream>
using namespace std;

int N;
int honey[100005], sum[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    int h;
    for(int i = 1; i <= N; i++) {
        cin >> honey[i];
        sum[i] = sum[i-1] + honey[i]; 
    }
    int ans = 0;
    for(int i = 2; i < N; i++) {
        ans = max(ans, (sum[N]-honey[1]-honey[i])+(sum[N]-sum[i]));
        ans = max(ans, (sum[i]-honey[1])+(sum[N-1]-sum[i-1]));
        ans = max(ans, sum[i-1]+(sum[N-1]-honey[i]));
    }
    cout << ans;
}