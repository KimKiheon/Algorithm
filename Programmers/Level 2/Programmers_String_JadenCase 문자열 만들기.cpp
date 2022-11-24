#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 1; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            s[i] += 32;
        }
    }

    if ('a' <= s[0] && s[0] <= 'z')s[0] -= 32;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == ' ' && 'a' <= s[i + 1] && s[i + 1] <= 'z') {
            s[i + 1] -= 32;
        }
        if ('A' <= s[i] && s[i] <= 'Z' && s[i - 1] != ' ') {
            s[i] += 32;
        }
    }
    return s;
}