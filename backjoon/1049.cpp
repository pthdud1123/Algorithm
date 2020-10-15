#include<stdio.h>
#pragma warning(disable:4996)


/*#define SWAP(x,y,temp) ((temp)=(x),(x)=(y),(y)=(temp))

void swap(int list[], int a, int b) {
	int temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}

//1.피벗을 기준으로 2개의 부분리스트로 나눈다.
//2.피벗보다 작은 값은 모두 왼쪽 부분 리스트로, 크값은 오른쪽 부분리스트로 옮긴다.
//2개의 비균등 배열 list[left...pivot-1]과list[pivot+1,,,,right]의 합병 과정
//Actual numbersorting process

int partition(int list[], int left, int right) {
	int pivot= list[left], temp;
	int low=left+1, high=right;
	while (low <= high) {
		//교차되기 전까지 반복한다
		while (pivot >= list[low] && low <= right) {
			low++;
		}
		while (pivot <= list[high] && high >= (left + 1)) {
			//피벗보다 작은 값을 찾는 과정
			high--;//high를 왼쪽으로 이동
		}
		if (low <= high) {
			//교차가 되지 않은 상태이면 스왑 과정 실행
			swap(list, low, high);//low와 high를 스왑
		}
	}
	swap(list, left, high);//피벗과 high를 가리키는 대상을 교환
	return high;
}

// 퀵정렬

void q_sort(int list[], int left, int right) {
	//정렬할 범위가 2개 이상의 데이터 이면(0이나 1이 아니면)
	if (left <= right) {
		//partition함수를 호출하여 피벅을 기준으로 리스트를 비균등 분할-분할
		int q = partition(list, left, right);//q:피먹의 위치

		//피멋은 2개의 부분 리스트를 대상으로 순환 호출
		q_sort(list, left, q - 1);//(left~피벗 바로 앞)앞쪽 부분리스트 정렬-정복
		q_sort(list, q + 1, right);
	}
}
*/

int main() {
	int N, M;//N:끊어진 키타줄의 개수 M:기타줄의 브랜드 수
	//각각의 브랜드에서 파는 기타줄 6개
	//패키지의 가격 낱개로 살때의 가격이 주어질때 적어도 N개를 사기위해 필요한 돈의 수를 최소로하는 프로그램
	//N<=100 M<=50
	//둘째 줄 부터 M개의 줄에는 각 브랜드의 패키지 가격과 낱개의 가격이 공백으로 주어짐
	//끊어진 줄의 개수     브랜드수
	//각각의 브랜드마다
	//패키지 가격          낱개 가격

	int Piece=0;//낱개가격 리스트
	int Bundle=0;//묶음 가격
	int case1 = 0, case2 = 0, case3 = 0;//1:piece인 가격2:piece+bundle3:allbundle
	int min = 0;//가장 최소인거

	scanf("%d %d", &N, &M);
	scanf("%d %d", &Bundle, &Piece);
	for (int i = 1;i < M;i++) {
		int p, b;
		scanf("%d %d", &b, &p);
		if (Bundle > b) {
			Bundle = b;
		}
		if (Piece > p) {
			Piece = p;
		}
 	}

	case1 = Piece * N;
	case2 = (Bundle * (N / 6)) + Piece * (N % 6);
	int b = N % 6;
	if (b == 0) {
		case3 = Bundle * (N/6);
	}
	else
		case3 = Bundle * ((N/6)+1);
	
	min = case1;

	if (min >= case2) {
		min = case2;
		if (min >= case3)
			min = case3;
	}
	else {
		if (min >= case3)
			min = case3;
	}
	
	printf("%d", min);
	//scanf("%d", &N);
	return 0;

}