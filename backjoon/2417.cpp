#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

//ceil()�Լ��� �Ҽ��� �ڸ��� ���ڸ� ������ �ø��� �Լ��̴�.
//floor()�Լ��� ��״�� �ٴ����� �����. �Ҽ��� �Ʒ��� ����

//�˰��� �м�
/*1.�̺�Ž���� �̿���Ǯ��->�翬�� start��end�� �����ϰ� mid�� ã�ư��� ���� ã�Ƴ��� �ȴ�.
2.������Ǯ��->root���� ������ �亸�� �۴ٸ�+1�� ���� ������ �ɰ��̴�.
*/
int main() {
	long long N;
	scanf("%lld", &N);
	long long n = sqrt(N);
	long long value = pow(n, 2);
	if (value != N) {
		n += 1;
	}
	printf("%lld", n);


	return 0;
}