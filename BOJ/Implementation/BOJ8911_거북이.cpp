#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int main() {
	int t;
	string str;
	cin >> t;
	while(t--) {
		cin >> str;
		int cx = 0, cy = 0, cd = 0, minx = 0, maxx = 0, miny = 0, maxy = 0;
		for (int i = 0; i < str.size(); i++) {
			char c = str[i];
			if (c == 'L' || c == 'R') {
				if (c == 'L')
					cd = (cd + 3) % 4;
				else
					cd = (cd + 1) % 4;
			}
			else {
				if (c == 'F') {
					cx += dx[cd];
					cy += dy[cd];
				}
				else {
					cx -= dx[cd];
					cy -= dy[cd];
				}
				maxx = max(cx, maxx);
				maxy = max(cy, maxy);
				minx = min(cx, minx);
				miny = min(cy, miny);
			}
		}
		cout << (maxx - minx) * (maxy - miny) << '\n';
	}
	return 0;
}