#include <iostream>
using namespace std;
int arr[605][605];
int map[605][605];
int a, b, c, d;
int main() {
    cin >> a >> b >> c >> d;
    int row = a + c;
    int col = b + d;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            map[i][j] = arr[i][j];
        }
    }
    for (int i = c; i <= row; i++) {
        bool chk = false;
        for (int j = d; j <= col; j++) {
            if (map[i][j] != 0) {
                map[i][j] -= map[i - c][j - d];
                chk = true;
            }
        }
        if (!chk) break;
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            cout << map[i][j];
        cout << "\n";
    }


    return 0;
}