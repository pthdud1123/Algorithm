#include<stdio.h>
#pragma warning(disable:4996)

void SWAP(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

int Partition(int arr[], int left, int right) {
	int pivot = arr[left];//피벗의 위치는 가장왼쪽에서 시작
	int low = left + 1;
	int high = right;
	while (low <= high) {//교차되기 전까지 반복한다.
		while (pivot >= arr[low] && low <= right) {//피벗보다 큰 값을 찾는 과정
			low++;//low를 오른쪽으로 이동
		}
		while (pivot <= arr[high] && high >=(left + 1)) {//피벗보다 작은 값을 차즌 과정
			high--;
		}
		if (low <= high) {//교차되지 않은 상태이면 스왑 과정
			SWAP(arr, low, high);//low와 high를 스왑
		}

	}
	SWAP(arr, left, high);//피벗과high가 가리키는 대상을 교환
	return high;//옯겨진 피벗의 위치 정보를 반환
}

void q_sort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = Partition(arr, left, right);// 둘로나누어서 피벗을 구한다.
		q_sort(arr, 0, pivot - 1);//왼쪽영역을 정렬한다.
		q_sort(arr, pivot + 1, right);//오른쪽 영역을 정렬한다.

	}
}

int main() {
	int N;
	int arr[1000];
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}
	q_sort(arr, 0, N - 1);//오름차순으로 정렬하고 자하는 배열과, 처음 과 끝

	//정렬후
	for (int i = 0;i < N;i++) {
		printf("%d\n", arr[i]);
	}
	//scanf("%d", &N);
	return 0;
}