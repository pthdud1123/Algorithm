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
void main() {


	string pelindrome;

	cin >> pelindrome;


	int size = pelindrome.size() - 1;
	bool pelin_check[2002][2002] = { 1, };
	int pelin_count[2002]= { 1, },pelin_index[2002][2002];//자기자신 
	int result = 0;//결과 값

	//각 원소의 위치에서 pelindrome이 가능한 원소 구하기
	for (int i = 0;i <= size;i++) {
		pelin_check[i][i] = true;
		int index = 0;
		for (int j = size;j > i;j--) {
			if (pelindrome[i] == pelindrome[j]) {
				bool key = check(pelindrome, i, j);
				pelin_check[i][j] = true;
				pelin_count[i]++;
				pelin_index[i][index] = j;
				index++;
			}

		}
	}

	int min = 3000, count;

	for (int i = 0;i <= size;i++) {
		count = i;
		for (int j = 0;j < pelin_count[i];j++) {
			count++;
			int next = pelin_index[i][j]+1;
			while (1) {
				if (next > size) {
					break;
				}
				else if (next == size) {
					count++;
					break;
				}
				count++;
				next = pelin_index[next][0] + 1;

			}
			if (min > count) {
				min = count;
			}
		}
	}
	cout << count;

}