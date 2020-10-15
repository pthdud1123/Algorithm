#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int POW(int a) {
	int num = 0;
	int value;
	while (1) {
		value = pow(2, num);
		if (value == a)
			return 1;
		else if (value > a)
			return 0;
		num++;
	}
}
int main() {
	int N,V;
	scanf("%d", &N);
	V = POW(N);
	printf("%d", V);
	return 0;
}