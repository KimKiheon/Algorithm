#include <string>
#include <vector>

using namespace std;
int check[105];
vector<int> solution(vector<int> pro, vector<int> speed) {
	vector<int> ans;
	int cur = 0, flag = 0;
	//cur = 배포된 기능의 수 = 배포가 시작되어야할 번호
	//flag = 배포 전 완성된 기능의 번호
	while (cur < pro.size()) {//배포된 기능의 수가 작업의 갯수보다 작을 동안 loop 
		for (int i = cur; i < pro.size(); i++) { //작업 진도 증가 작업
			if (pro[i] >= 100)continue;
			pro[i] += speed[i];
		}
		for (int i = cur; i < pro.size(); i++) {//작업진도 100이상이 되어 배포할 작업이 있는지 체크
			if (pro[i] < 100)break;
			flag = i + 1; // 완성되어 배포 준비가 된 기능
		}
		if (flag != cur) {//배포 전이지만 완성된 기능이 있는지
			ans.push_back(flag - cur);//완성된 기능 수 List에 추가
			cur = flag; //배포 완료
		}
	}
	return ans;
}