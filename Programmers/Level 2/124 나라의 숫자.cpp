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
1,2,4 세 개의 숫자를 사용하는 것을 통해 3진수로 접근
3진수의 0,1,2를 1,2,4로 변환하자 1씩 차이나는 것을 확인하여 1씩 빼면서 풀이
*/