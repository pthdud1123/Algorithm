#include<stdio.h>
#pragma warning(disable:4996)

void mergeSort(int data[], int s, int e) {
	int tmp[10000];
	int i = s;
	int k = s;
	int m = (s + e) / 2;
	int j = m + 1;
	if (s >= e)return;//쪼갤 수없음, 되돌아가기
	mergeSort(data, s, m);
	mergeSort(data, m + 1, e);
	while ((i <= m) && (j <= e)) {
		if (data[i] < data[j])
			tmp[k++] = data[i++];
		else
			tmp[k++] = data[j++];
	}
	while (i <= m)tmp[k++] = data[i++];//나머지 병합
	while (j <= e)tmp[k++] = data[j++];//나머지 병합
	for (i = s;i <= e;i++)data[i] = tmp[i];//복사
}

int main() {
	int N,h=2;
	int arr[1000];
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}
	mergeSort(arr,0,N-1);//N==sizeof(arr)/sizeof(int):배열의 크기 ->인덱스는 여기서 하나 작으니까 -1
	
	for (int i = 0;i < N;i++) {
		printf("%d\n", arr[i]);
	}
	//scanf("%d", &N);
	return 0;
}
/*nlogn의 시간 복잡도를 가지는 정렬 알고리즘에 대해 알아보자
nlog n 에 최악의 시간복잡도를 사지는 것->O(n log n)인 정렬 알고리즘에는 Merge Sort ,Heap Sort가 있음
퀵정렬->분할 정복을 통해 정렬
=>합병정렬도 마찬가지
※합병정렬은 원소를 하나의 단위로 분할한 후 분할 한 원소를 다시 합병하는 정렬 방식
1.리스트의 길이가 1이 될때까지 반으로 잘게 나눈다->분할
2.다 나누어 졌다면, 데이터를 합치는데(Merge),정렬하면서 합친다.
기본적으로 병합정렬은 재귀함수로 구현한다.
반으로 쪼개서 다시 재귀함수 호출하고 호출한 결과를 가지고 정렬을 한다.
*/