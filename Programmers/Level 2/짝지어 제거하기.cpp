#include <string>
#include <iostream>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    int answer = 0;
    if (s.size() % 2 == 1)return answer;
    for (int i = 0; i < s.size(); i++) {
        if (!st.size() || st.top() != s[i])st.push(s[i]);
        else {
            if (s[i] == st.top())st.pop();
        }
    }
    if (!st.size())answer = 1;
    return answer;
}
/*
단순 반복문으로 구현할 시 입력받는 문자열의 길이가 최대 1,000,000이기 때문에 
시간초과가 날 수 있다.
처음에는 반복문으로 접근하려 했으나 NlogN 안에 해결할 방법이 생각나지 않아 
Stack을 이용하여 접근하였다.

*/