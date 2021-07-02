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
�ܼ� �ݺ������� ������ �� �Է¹޴� ���ڿ��� ���̰� �ִ� 1,000,000�̱� ������ 
�ð��ʰ��� �� �� �ִ�.
ó������ �ݺ������� �����Ϸ� ������ NlogN �ȿ� �ذ��� ����� �������� �ʾ� 
Stack�� �̿��Ͽ� �����Ͽ���.

*/