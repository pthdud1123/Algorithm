#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

bool check(string pelindrome, int start, int end) {
	int size = ceil(float((end - start - 1) / 2));
	for (int i = 1;i <= size;i++) {
		if (pelindrome[start + i] == pelindrome[end - i])
			continue;
		else
			return false;

	}
	return true;
}
int main() {


	string pelindrome;

	cin >> pelindrome;


	int size = pelindrome.size() - 1;
	int result[2002] = { 1, }, value = 0;//1�� �ʱ�ȭ
	bool key, str_check[2002][2002] = { 1, };//false�� �ʱ�ȭ

	for (int i = 0;i <= size;i++) {
		for (int index = size;index > i;index--) {
			if (pelindrome[i] == pelindrome[index]) {
				key = check(pelindrome, i, index);
				if (key) {
					result[i]++;
					str_check[i][index] = true;//���� üũ�����൵ �ɰ� ����
				}
			}
		}
	}

	for (int i = 0;i <= size;i++) {

	}








}