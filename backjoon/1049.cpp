#include<stdio.h>
#pragma warning(disable:4996)


/*#define SWAP(x,y,temp) ((temp)=(x),(x)=(y),(y)=(temp))

void swap(int list[], int a, int b) {
	int temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}

//1.�ǹ��� �������� 2���� �κи���Ʈ�� ������.
//2.�ǹ����� ���� ���� ��� ���� �κ� ����Ʈ��, ũ���� ������ �κи���Ʈ�� �ű��.
//2���� ��յ� �迭 list[left...pivot-1]��list[pivot+1,,,,right]�� �պ� ����
//Actual numbersorting process

int partition(int list[], int left, int right) {
	int pivot= list[left], temp;
	int low=left+1, high=right;
	while (low <= high) {
		//�����Ǳ� ������ �ݺ��Ѵ�
		while (pivot >= list[low] && low <= right) {
			low++;
		}
		while (pivot <= list[high] && high >= (left + 1)) {
			//�ǹ����� ���� ���� ã�� ����
			high--;//high�� �������� �̵�
		}
		if (low <= high) {
			//������ ���� ���� �����̸� ���� ���� ����
			swap(list, low, high);//low�� high�� ����
		}
	}
	swap(list, left, high);//�ǹ��� high�� ����Ű�� ����� ��ȯ
	return high;
}

// ������

void q_sort(int list[], int left, int right) {
	//������ ������ 2�� �̻��� ������ �̸�(0�̳� 1�� �ƴϸ�)
	if (left <= right) {
		//partition�Լ��� ȣ���Ͽ� �ǹ��� �������� ����Ʈ�� ��յ� ����-����
		int q = partition(list, left, right);//q:�Ǹ��� ��ġ

		//�Ǹ��� 2���� �κ� ����Ʈ�� ������� ��ȯ ȣ��
		q_sort(list, left, q - 1);//(left~�ǹ� �ٷ� ��)���� �κи���Ʈ ����-����
		q_sort(list, q + 1, right);
	}
}
*/

int main() {
	int N, M;//N:������ ŰŸ���� ���� M:��Ÿ���� �귣�� ��
	//������ �귣�忡�� �Ĵ� ��Ÿ�� 6��
	//��Ű���� ���� ������ �춧�� ������ �־����� ��� N���� ������� �ʿ��� ���� ���� �ּҷ��ϴ� ���α׷�
	//N<=100 M<=50
	//��° �� ���� M���� �ٿ��� �� �귣���� ��Ű�� ���ݰ� ������ ������ �������� �־���
	//������ ���� ����     �귣���
	//������ �귣�帶��
	//��Ű�� ����          ���� ����

	int Piece=0;//�������� ����Ʈ
	int Bundle=0;//���� ����
	int case1 = 0, case2 = 0, case3 = 0;//1:piece�� ����2:piece+bundle3:allbundle
	int min = 0;//���� �ּ��ΰ�

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