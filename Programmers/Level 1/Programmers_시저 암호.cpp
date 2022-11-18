#include<string>
#include<iostream>
#include<vector>
using namespace std;
string solution(string s, int n) {
	for (int i = 0; i < s.size(); i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			if ('z' < s[i] + n)s[i] -= 26;
			s[i] += n;
			continue;
		}
		if ('A' <= s[i] && s[i] <= 'Z') {
			if ('Z' < s[i] + n)s[i] -= 26;
			s[i] += n;
		}
	}
	return s;
}