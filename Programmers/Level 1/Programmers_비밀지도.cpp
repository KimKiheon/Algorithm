#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		arr1[i] = arr1[i] | arr2[i]; //OR����
	}
	for (int i = 0; i < n; i++) {
		string str;
		for (int j = n - 1; j >= 0; j--) {
			if ((arr1[i] >> j & 1))str += '#'; //2�������� ��ȯ�� 1�ϰ�� string�� # �߰�
			else str += " ";//0�ϰ�� ���� �߰�
		}
		answer.push_back(str); //����Ʈ�� str �߰�
	}
	return answer;
}