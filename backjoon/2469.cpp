#include<stdio.h>
#include<iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

int main() {
	//��ٸ� Ÿ��
	//����-���� ���밡 ����, ���� ���� �ż�-���� ���밡 ����
	//�Է¿��� ��ٸ��� ��ü ����� �� �ٿ� �ִ� ���� ������ ������ ǥ��
	//�� �ٿ��� ���� ���밡 ���� ��쿡�� * ���� ��쿡�� - �׸��� �J�߾��� Ư�� ���� �� �� ���� ���� k-1�� ?���ڿ��� ǥ��

	int k,n;//k:������ ����� ��,n:���� ���밡 ���� ��ü ���� ���� ���� ��Ÿ��
	string end;

	cin >> k;
	cin >> n;
	cin >> end;
	string start;
	for (int i = 0;i < k;i++) {
		start += (65 + i);
	}
	string sadari[1000];
	for (int i = 0;i < n;i++) {
			cin >> sadari[i];
	}

	for (int i = 0;i < n;i++) {
		if (sadari[i][0] == '?')
				break;
		for (int j = 0;j < k-1;j++) {
			if (sadari[i][j] == '-') {
				char temp;
				temp = start[j];
				start[j] = start[j + 1];
				start[j + 1] = temp;
			}
		}
	}
	for (int i = n-1;i >0;i--) {
		if (sadari[i][0] == '?')
			break;
		for (int j = 0;j < k-1;j++) {
			if (sadari[i][j] == '-') {
				char temp;
				temp = end[j];
				end[j] = end[j + 1];
				end[j + 1] = temp;
			}
		}
	}
	
	string result;



	for (int i = 0;i < k - 1;i++) {
		char a = start[i], b = end[i];

		if (a == b) {
			result += '*';
		}

		else if (a == end[i + 1] && start[i + 1] == b) {
			result += '-';
			if (i != k - 2) {
				i++;
				result += '*';

			}
		}
		else {
			result.clear();
			for (int t = 0;t < k - 1;t++) {
				result += 'x';
			}
			break;
		}
	}
	//printf("%s", result);
	for (int i = 0;i < k - 1;i++) {
		printf("%c", result[i]);
	}
	return 0;

}