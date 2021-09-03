#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

int pelin_check[2002][2002] = { 1, }, pelin_count[2002], pelin_index[2002][2002];//자기자신 


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

int pelindrome_count(string pelindrome, int start,int end, int min) {

	for (int j = 0;j < pelin_count[start];j++) {

		int count = 1,next;
		if (pelin_index[start][j] <= end) {
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
			count++;
			next = pelin_index[next][0] + 1;
		}
		if (min > count) {
			min = count;
		}
	}
	return min;
}

int main() {


	string pelindrome;

	cin >> pelindrome;


	int size = pelindrome.size() - 1;
	
	int result = 0;//결과 값

	//각 원소의 위치에서 pelindrome이 가능한 원소 구하기
	for (int i = 0;i <= size;i++) {
		pelin_count[i] = 1;
		int index = 0;
		for (int j = size;j > i;j--) {
			if (pelindrome[i] == pelindrome[j]) {
				bool key = check(pelindrome, i, j);
				if (key) {
					pelin_count[i]++;
					pelin_index[i][index] = j;
					index++;
				}
			}

		}
		pelin_index[i][index] = i;
	}

	int min = 3000, count=0;

	for (int i = 0;i <= size;i++) {
		if (i != 0) {
			//i=0부터 i=현재-1 부분 팰린드롬 최소갯수구하기
			int tmp_min = 3000;
			for (int ii = 0;ii < i;ii++) {
				count = ii;
				count += pelindrome_count(pelindrome, 0,i-1, tmp_min);
				if (tmp_min > count)
					tmp_min = count;
			}
			count = tmp_min;
		}
		count+=pelindrome_count(pelindrome, i,size, 3000);
		if (min > count) {
			min = count;
		}
		
	}
	cout << min;

}