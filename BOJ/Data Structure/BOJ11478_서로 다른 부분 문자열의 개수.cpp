#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<string> arr;
    string s;
    cin >> s;
    int l = s.size();
    for (int i = 0; i < l; i++) {
        for (int j = 1; j < l - i + 1; j++)
            arr.insert(s.substr(i, j));
    }
    cout << arr.size() << "\n";
    return 0;
}
