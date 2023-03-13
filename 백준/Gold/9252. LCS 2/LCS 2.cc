#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
string str1, str2, tmp, ans;
vector<char>v;
int arr[1005][1005];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> tmp;
    str1 = '0' + tmp;
    cin >> tmp;
    str2 = '0' + tmp;
    int l1 = str1.size(), l2 = str2.size();
    for (int i = 1; i < l1; i++) {
        for (int j = 1; j < l2; j++) {
            if (str1[i] == str2[j]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                continue;
            }
            arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    int i = l1 - 1, j = l2 - 1;
    while (i&&j) {
        int tmp = arr[i][j];
        if (arr[i][j - 1] == tmp)j--;
        else if (arr[i - 1][j] == tmp)i--;
        else if (tmp - 1 == arr[i - 1][j - 1]){
            ans = str1[i] + ans;
            i--, j--;
        }

    }
    cout << arr[l1 - 1][l2 - 1]<<"\n";
    if (!arr[l1 - 1][l2 - 1])return 0;
    cout << ans;
    return 0;
}