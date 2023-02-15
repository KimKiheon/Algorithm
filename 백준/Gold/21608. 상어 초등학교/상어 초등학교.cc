#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int, int>p;
int n, cnt = 1, ans;
vector<vector<int>>v, vv, map;
vector<vector<p>>like; //<like, blank>
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int sumLike[5] = { 0,1,10,100,1000 };

int isValid(int x, int y, int i) { //(x,y)위치에서 i방향이 경계값을 벗어나는지
	if (x + dx[i] < 0 || n - 1 < x + dx[i] || y + dy[i] < 0 || n - 1 < y + dy[i])return 0;
	return 1;
}
int returnLike(int x, int y, int d) { //(x,y)위치에서 d방향에 좋아하는 학생이 있는지
	for (int i = 1; i <= 4; i++) {
		if (map[x + dx[d]][y + dy[d]] == v[cnt][i]) return 1;
	}
	return 0;
}
void input() {
	cin >> n;
	v.resize(n*n);
	map.resize(n);
	like.resize(n);
	for (int i = 0; i < n*n; i++) {
		if (i < n)map[i].resize(n);
		for (int j = 0; j < 5; j++) {
			int a;
			cin >> a;
			v[i].push_back(a);
		}
		sort(v[i].begin() + 1, v[i].end());
	}
	for (int i = 0; i < n; i++) like[i].resize(n);
}
int searchMaxLike() { //최대 선호도 수 구하기
	int maxLike = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j])continue;
			for (int k = 0; k < 4; k++) {
				if (isValid(i, j, k)) {
					if(map[i+dx[k]][j+dy[k]])	like[i][j].first += returnLike(i, j, k);
					else like[i][j].second ++;
				}
			}
			maxLike = max(maxLike, like[i][j].first);
		}
	}
	return maxLike;
}
void insertStudent(int maxLike, int maxBlank) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j]&&like[i][j].first == maxLike && like[i][j].second == maxBlank) { //map에 아직 채워지지 않은 자리중 선호도와 주변 빈칸이 가장 많은 자리
				map[i][j] = v[cnt][0];
				return;
			}
		}
	}
}
int searchMaxBlank(int maxLike){ //선호도가 최고인 곳들 중에서 4방향 탐색하며 maxBlank 구하기
	int maxBlank = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (like[i][j].first == maxLike)maxBlank = max(maxBlank, like[i][j].second);
	return maxBlank;
}
void likeInit() { //like vector {0,0} 초기화
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)like[i][j] = { 0, 0 };
}
void vvInit() {
	for (int i = 0; i < n * n; i++) 
		for (int j = 0; j < 4; j++)
			vv[v[i][0]].push_back(v[i][j + 1]);
}
int ansSum(int x, int y) {
	int sum = 0;
	for (int i = 0; i < 4; i++) { //(x,y)기준 4방향 검사
		if (!isValid(x, y, i)) continue;
		for (int j = 0; j < 4; j++) { //방향에 선호하는 친구가 있는지??
			if (map[x + dx[i]][y + dy[i]] == vv[map[x][y]][j]) sum++;
		}
	}
	return sumLike[sum];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	input();
	map[1][1] = v[0][0];
	while (cnt < n*n) {
		p maxi; //cnt번째로 입력된 학생기준 자리별 선호도, 4방향 공백 최대값 <int,int> 
		maxi.first = searchMaxLike(); //자리별 선호도 최대값 구하기
		maxi.second = searchMaxBlank(maxi.first);//자리별로 선호도가 max인 곳들 중 4방향 빈칸 최대 수
		insertStudent(maxi.first, maxi.second);// n*n map에서 좌측 상단부터 우측 하단까지 탐색하며 선호도, 주변 빈칸 최대값인 곳에 삽입
		likeInit(); //선호도 조사한 배열 0으로 초기화
		cnt++;
	}
	//여기까진 틀렸습니다! 
	vv.resize(v.size() + 1);
	vvInit();
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)ans += ansSum(i, j);
	cout << ans << "\n";
	return 0;
}
