#include<stdio.h>
#pragma warning(disable:4996)

void SWAP(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

int Partition(int arr[], int left, int right) {
	int pivot = arr[left];//�ǹ��� ��ġ�� ������ʿ��� ����
	int low = left + 1;
	int high = right;
	while (low <= high) {//�����Ǳ� ������ �ݺ��Ѵ�.
		while (pivot >= arr[low] && low <= right) {//�ǹ����� ū ���� ã�� ����
			low++;//low�� ���������� �̵�
		}
		while (pivot <= arr[high] && high >=(left + 1)) {//�ǹ����� ���� ���� ���� ����
			high--;
		}
		if (low <= high) {//�������� ���� �����̸� ���� ����
			SWAP(arr, low, high);//low�� high�� ����
		}

	}
	SWAP(arr, left, high);//�ǹ���high�� ����Ű�� ����� ��ȯ
	return high;//������ �ǹ��� ��ġ ������ ��ȯ
}

void q_sort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = Partition(arr, left, right);// �ѷγ���� �ǹ��� ���Ѵ�.
		q_sort(arr, 0, pivot - 1);//���ʿ����� �����Ѵ�.
		q_sort(arr, pivot + 1, right);//������ ������ �����Ѵ�.

	}
}

int main() {
	int N;
	int arr[1000];
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}
	q_sort(arr, 0, N - 1);//������������ �����ϰ� ���ϴ� �迭��, ó�� �� ��

	//������
	for (int i = 0;i < N;i++) {
		printf("%d\n", arr[i]);
	}
	//scanf("%d", &N);
	return 0;
}