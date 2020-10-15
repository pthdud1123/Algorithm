#include<stdio.h>
#pragma warning(disable:4996)

static int arr[9];
int MAX=0;


void swap(int i, int j) {
	if (i == j)
		return ;
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Permutation(int TotalN, int N) {
	int i;
	if (N == 1) {
		int sum = 0;
		for (int i = 0;i < TotalN-1;i++) {
			int R;
			if (arr[i] <= arr[i + 1]) {
				R = arr[i + 1] - arr[i];
			}
			else {
				R = arr[i] - arr[i + 1];
			}
			sum += R;
		}
		if (MAX < sum) {
			MAX = sum;
		}
		
		return;
	}
	for (int i = 0;i < N;i++) {
		swap(i, N - 1);
		Permutation(TotalN, N - 1);
		swap(i, N - 1);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}
	Permutation(N, N);
	printf("%d", MAX);
	return 0;


}