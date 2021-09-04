#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

int pelin_check[2002][2002] = { 1, }, pelin_count[2002];
bool pelin_index[2002][2002];//�ڱ��ڽ� 


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

int pelindrome_count(string pelindrome, int start, int end, int min) {

	for (int j = 0;j < pelin_count[start];j++) {

		int count = 1, next;
		if (j <= end) {
			next = pelin_index[start][j] + 1;
		}
		else {
			next = j + 1;
		}
		while (1) {
			if (next > end) {
				break;
			}
			else if (next == end) {
				count++;
				break;
			}
			for (int k = 0;k < pelin_count[next];k++) {
				if (pelin_index[next][k] <= end) {
					count++;
					next = pelin_index[next][k] + 1;
					break;
				}
			}
		}
		if (min > count) {
			min = count;
		}
	}
	return min;
}

int main() {

	ios::sync_with_stdio(false);
	string pelindrome;

	cin >> pelindrome;


	int size = pelindrome.size() - 1;

	int result = 0;//��� ��

	//�� ������ ��ġ���� pelindrome�� ������ ���� ���ϱ�
	for (int i = 0;i <= size;i++) {
		pelin_count[i] = 1;
		for (int j = size;j > i;j--) {
			if (pelindrome[i] == pelindrome[j]) {
				bool key = check(pelindrome, i, j);
				if (key) {
					pelin_count[i]++;
					pelin_index[i][j] = true;
				}
			}

		}
	}

	int min = 3000, count = 0;

	for (int i = 0;i <= size;i++) {
		if (i != 0) {
			//i=0���� i=����-1 �κ� �Ӹ���� �ּҰ������ϱ�
			int tmp_min = 3000;
			for (int ii = 0;ii < i;ii++) {
				count = ii;
				count += pelindrome_count(pelindrome, ii, i - 1, tmp_min);
				if (tmp_min > count)
					tmp_min = count;
			}
			count = tmp_min;
		}
		count += pelindrome_count(pelindrome, i, size, 3000);
		if (min > count) {
			min = count;
		}

	}
	cout << min;

}