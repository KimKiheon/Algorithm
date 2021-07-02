#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    int ans = 0;
    while (n > 0) {
        n--;
        int tmp;
        tmp = n % 3;
        n /= 3;
        if (tmp == 0)tmp = 1;
        else if (tmp == 1)tmp = 2;
        else if (tmp == 2)tmp = 4;
        answer += to_string(tmp);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
/*
1,2,4 �� ���� ���ڸ� ����ϴ� ���� ���� 3������ ����
3������ 0,1,2�� 1,2,4�� ��ȯ���� 1�� ���̳��� ���� Ȯ���Ͽ� 1�� ���鼭 Ǯ��
*/