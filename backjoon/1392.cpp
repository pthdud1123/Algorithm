#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int N,Q;//N악보수Q질문의 개수
	int S_Music[10000];//악보마다 걸리는 시간 배열에 담기
	int a;
	//N개의 줄에는 1번 악보 부터 N번악보까지  차지하는 시간이 한 줄에 주어진다.
	//다음 Q개의 줄에는 알고자하는 Q개의 시간 이 한 줄에 하나씩 주어진다.

	scanf("%d %d", &N, &Q);

	int num = 1;
	int index = 0;
	for (int i = 0;i < N;i++) {

		scanf("%d", &a);
		for (int j = 0;j < a;j++) {
			S_Music[index] = num;
			index++;
		}
		num++;

	}
	for (int i = 0;i < Q;i++) {
		scanf("%d", &a);
		printf("%d\n", S_Music[a]);
	}
	
	//scanf("%d", &a);
	return 0;
}