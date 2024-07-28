#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p, m;
    for(int i = 0 ; i < n; i++){
        int c; cin >> c;
        if(c > 0) p.push_back(c);
        else m.push_back(c);
    }
    int ans = 0;
    sort(p.begin(), p.end(), greater<>());
    sort(m.begin(), m.end());
    
    if(p.size() % 2 != 0) ans += p[p.size() - 1];
    
    for(int i = 0; i < (int) p.size() - 1;){
        if(p[i + 1] == 1) ans += p[i] + p[i + 1];
        else if(p[i + 1] > 0) ans += p[i] * p[i + 1];
        i+=2;
    }
    
    if(m.size() % 2 != 0) ans += m[m.size() - 1];
    
    for(int i = 0; i < (int) m.size() - 1; i+=2){
        ans+= m[i] * m[i + 1];
    }
    cout << ans << "\n";
}