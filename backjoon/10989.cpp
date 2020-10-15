#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)


int main() {
	int N;
	int arr[10001] = {0,};//숫자가 몇개인지 체크 할 개수
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		int a;
		scanf("%d", &a);
		arr[a] += 1;
	}
	for (int i = 0;i <= 10000;i++) {
		if (arr[i] != 0) {
			for (int j = 0;j < arr[i];j++) {
				printf("%d\n", i);
			}
		}
	}
	//scanf("%d", &N);
	return 0;


}