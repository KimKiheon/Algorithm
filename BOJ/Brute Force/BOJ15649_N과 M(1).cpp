#include<iostream>
using namespace std;
int arr[10], num, depth;
bool check[10];
void go(int idx, int n, int d) { //idx = ���� �ε��� ��ġ, n = num d = depth
	if (idx == d) {//���� �ε��� ��ġ�� depth������ ���޽� (����) ���
		for (int i = 0; i < d; i++) cout<<arr[i]+" ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {//i�� ������� �ʾҴٸ�
			check[i] = true; //��� üũ ���ְ�
			arr[idx] = i;//����� �迭�� �־��ش�
			go(idx + 1, n, d);//����Լ� ȣ��
			check[i] = false;
			arr[idx] = 0;//����� �������� �迭�� ������ �����ְ� ���üũ�� �����ش�
		}
	}
}
int main() {
	cin >> num >> depth;
	go(0, num, depth);
	return 0;
}