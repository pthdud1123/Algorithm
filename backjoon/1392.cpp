#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int N,Q;//N�Ǻ���Q������ ����
	int S_Music[10000];//�Ǻ����� �ɸ��� �ð� �迭�� ���
	int a;
	//N���� �ٿ��� 1�� �Ǻ� ���� N���Ǻ�����  �����ϴ� �ð��� �� �ٿ� �־�����.
	//���� Q���� �ٿ��� �˰����ϴ� Q���� �ð� �� �� �ٿ� �ϳ��� �־�����.

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