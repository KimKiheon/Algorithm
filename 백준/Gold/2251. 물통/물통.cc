#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<pair<int, int>, int>p;
int A, B, C;
bool check[202][202][202];
vector<int> v;

void go(){
    queue<p> q;
    q.push({ {0, 0}, C });

    while (!q.empty()){
        p now = q.front();
        int a = now.first.first;
        int b = now.first.second;
        int c = now.second;
        q.pop();

        if (check[a][b][c] == true) continue;
        check[a][b][c] = true;

        if (a == 0) v.push_back(c);

        if (a + b > B) q.push({ {a + b - B, B }, c }); //A->B
        else q.push({ {0, a + b}, c });

        if (a + c > C) q.push({ {a + c - C, b}, C }); //A C
        else q.push({{0, b}, a + c});

        if (b + a > A) q.push({ {A, b + a - A}, c }); //B A
        else q.push({ {b + a, 0}, c });

        if (b + c > C) q.push({ {a, b + c - C}, C }); //B C
        else q.push({ {a, 0}, b + c });

        if (c + a > A) q.push({ {A, b}, c + a - A }); //C A
        else q.push({ {c + a, b}, 0 });

        if (c + b > B) q.push({ {a, B}, c + b - B }); //C B
        else q.push({ {a, b + c}, 0 });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)cout << v[i] << " ";
}



int main(void) {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> A >> B >> C;
    go();
    return 0;
}