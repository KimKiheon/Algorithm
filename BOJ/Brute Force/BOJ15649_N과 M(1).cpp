#include<iostream>
using namespace std;
int arr[10], num, depth;
bool check[10];
void go(int idx, int n, int d) { //idx = 현재 인덱스 위치, n = num d = depth
	if (idx == d) {//현재 인덱스 위치가 depth끝까지 도달시 (기저) 출력
		for (int i = 0; i < d; i++) cout<<arr[i]+" ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {//i를 사용하지 않았다면
			check[i] = true; //사용 체크 해주고
			arr[idx] = i;//출력할 배열에 넣어준다
			go(idx + 1, n, d);//재귀함수 호출
			check[i] = false;
			arr[idx] = 0;//사용이 끝났으면 배열에 내용을 지워주고 사용체크도 지워준다
		}
	}
}
int main() {
	cin >> num >> depth;
	go(0, num, depth);
	return 0;
}