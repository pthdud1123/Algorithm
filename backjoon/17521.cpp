#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	long long n, w;//n:���� �� ,w:�ʱ�����
	long long coin=0;//���� ����
	int bytecoin[16];
	bool buy = false;//���� �Ȼ�
	cin >> n >> w;
	for (int i = 1;i <= n;i++) {
		cin >> bytecoin[i];
	}
	for (int i = 1;i <= n;i++) {
		if (i != n && bytecoin[i] < bytecoin[i + 1] && buy == false) {
			coin = w / bytecoin[i];//���λ��
			w -= coin * bytecoin[i];//���� ��� ���� ��
			buy = true;//������ �˸���.
		}
		if (i!=n&&buy == true && bytecoin[i] > bytecoin[i + 1]) {
			w += coin * bytecoin[i];
			coin = 0;
			buy = false;//�ȾҴ�~
		}
		if (i == n&&buy==true) {
			w += coin * bytecoin[i];
		}
	}
	cout << w;

}