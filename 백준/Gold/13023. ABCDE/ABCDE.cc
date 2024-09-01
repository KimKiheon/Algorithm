#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v[2005];
vector<bool> check(2005, false);

void dfs(vector<int> list){
    int now = list.back();
    if(list.size() > 1){
       for(int i = 0; i <= list.size() - 2; i++){
            if(list[i] == now)
                return;
       }
       if(list.size() == 5){
            cout << 1 << '\n';
            exit(0);
       }
    }
    for(int i = 0; i < v[now].size(); i++){
        list.push_back(v[now][i]);
        dfs(list);
        list.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        check[a] = true;
        check[b] = true;
    }
    vector<int> list;
    for(int i = 0; i < check.size(); i++){
        if(!check[i]) continue;

        list.push_back(i);
        dfs(list);
        list.pop_back();
    }

    cout << 0 << '\n';
    return 0;
}