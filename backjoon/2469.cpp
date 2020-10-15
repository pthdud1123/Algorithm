#include<stdio.h>
#include<iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

int main() {
	//사다리 타기
	//점선-가로 막대가 없음, 굵은 가로 신선-가로 막대가 잇음
	//입력에서 사다리의 전체 모양은 각 줄에 있는 가로 막대의 유무로 표현
	//각 줄에서 가로 막대가 없는 경우에는 * 있을 경우에는 - 그리고 갘추어진 특정 가로 줄 은 줄의 길이 k-1인 ?문자열로 표시

	int k,n;//k:참가한 사람의 수,n:가로 막대가 놓일 전체 가로 줄의 수를 나타냄
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