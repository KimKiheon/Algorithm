#include <string>
#include <vector>

using namespace std;
int check[105];
vector<int> solution(vector<int> pro, vector<int> speed) {
	vector<int> ans;
	int cur = 0, flag = 0;
	//cur = ������ ����� �� = ������ ���۵Ǿ���� ��ȣ
	//flag = ���� �� �ϼ��� ����� ��ȣ
	while (cur < pro.size()) {//������ ����� ���� �۾��� �������� ���� ���� loop 
		for (int i = cur; i < pro.size(); i++) { //�۾� ���� ���� �۾�
			if (pro[i] >= 100)continue;
			pro[i] += speed[i];
		}
		for (int i = cur; i < pro.size(); i++) {//�۾����� 100�̻��� �Ǿ� ������ �۾��� �ִ��� üũ
			if (pro[i] < 100)break;
			flag = i + 1; // �ϼ��Ǿ� ���� �غ� �� ���
		}
		if (flag != cur) {//���� �������� �ϼ��� ����� �ִ���
			ans.push_back(flag - cur);//�ϼ��� ��� �� List�� �߰�
			cur = flag; //���� �Ϸ�
		}
	}
	return ans;
}