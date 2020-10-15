#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int size = 5;
	int sum = 0,value;
	
	for (int i = 0;i < size;i++) {
	
		scanf("%d", &value);
		sum += value;
	
	}

	printf("%d", sum);
	scanf("%d", &value);

}