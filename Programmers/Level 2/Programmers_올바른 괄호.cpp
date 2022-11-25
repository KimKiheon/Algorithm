#include<string>
#include<stack>
using namespace std;

bool solution(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')cnt++;
        else {
            if (!cnt)return false;
            cnt--;
        }
    }

    return !cnt;
}