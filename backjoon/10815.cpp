#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)


int arr[500000];
int main() {
	int N, M;//N:상근이의 숫자카드 수
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}
	std::sort(arr, arr + N); 

	scanf("%d", &M);
	for (int i = 0;i < M;i++) {
		int result = 0,find;
		scanf("%d", &find);
		int mid, left = 0,right = N - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (find > arr[mid]) {
				left = mid + 1;
			}
			else if (find < arr[mid]) {
				right = mid - 1;
			}
			else {
				result = 1;
				break;
			}
		}
		printf("%d ", result);
	}
	//scanf("%d", &N);
	return 0;
}