#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int M, N, L, x, y, cnt = 0;
    vector<int> m;
    cin >> M >> N >> L;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        m.push_back(tmp);
    }
    sort(m.begin(), m.end());
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (y > L) continue;
        int upper = x + L - y, lower = x + y - L, low = 0, high = m.size() - 1; // x+=r에 사로가 있으면 됨
        while (low <= high) {
            int mid = (low + high) / 2;
            if (lower <= m[mid] && m[mid] <= upper) {
                cnt++;
                break;
            }
            else if (m[mid] < lower) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    printf("%d\n", cnt);
}