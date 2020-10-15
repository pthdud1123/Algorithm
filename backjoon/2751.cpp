#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)

/*
void SWAP(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

int Partition(int arr[], int left, int right) {
	
	int pivot = arr[left];
	int low = left + 1, high = right;
	while (low <= high) {
		while (pivot >= arr[low] && low <= right) {
			low++;
		}
		while (pivot <= arr[high] && high >= (left + 1)) {
			high--;
		}
		if (low <= high) {
			SWAP(arr, low, high);
		}
	}
	SWAP(arr, left, high);//피벗과 high가 가르 키는 대상을 교환
	return high;
}

void q_sort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = Partition(arr, left, right);
		q_sort(arr, 0, pivot - 1);
		q_sort(arr, pivot + 1, right);
	}
}*/
int arr[1000000] = { 0, };

int main() {
	
	int N;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}
	std::sort(arr,arr+N);
	for (int i = 0;i < N;i++) {
		printf("%d\n", arr[i]);
	}
	scanf("%d", &N);
	return 0;

}