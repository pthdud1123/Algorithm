#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

//Ʋ�ȴ����� -1�̸� ���ư��� �ȵǴµ� ���ư��� ����...
int main() {
	int n=0;//�Է¹��� ��

	
	while (n != -1) {

		scanf("%d", &n);
		if (n == -1)
			break;

		//n�� -1�ϰ�� ��
		int measure[50] = { 0, };//������� ������ ����
		measure[0] = 1;//������ �׻� 1�� ����� ������.
		int i=2,num=1,sum=1;// n�� ������,sum�׻� 1�� �����ְ� �ִ´�.
		//��� ���ϱ�
		for ( i = 2;i*i < n;i++) {
			if (n%i == 0) {
				measure[num] = i;
				measure[num + 1] = n / i;
				sum += measure[num];
				sum += measure[num+1];
				
				num += 2;

			}
		}
		if (i*i == n) {
			measure[num] = i;
			sum += i;
		}
		sort(measure, measure + num);

		
		if (sum == n&&sum!=1) {
			printf("%d = 1", sum);
			for (int k = 1;k < num;k++) {
				printf(" + %d", measure[k]);
			}
		}
		else {
			printf("%d is NOT perfect.",n);
		}

		printf("\n");
		//��� �˰���
	}

	return 0;
}

/*
��� ���ϴ� ���α׷��� c���� ®��.
while (i != n) {
if (n%i == 0) {
measure[i] = 1;//����� ���ϰ�� 1
sum += i;
}
i++;
}
�����ϰԴ� ©�� ������ �������� �����ߴ�. 

�׷� �̰��� ��� �ٲ� ��������?
1�ܰ�)
for(int i=1;i<=n/2;i++){
if(n%i==0)
printf("%d",i);
}
������� ������ �غ���
10�� ��� ->1,2,5,10�̴� 
��10�� ������ ������ ���� �ʰ��� ���� ����� ����� �� �� ����. ->�翬�� �Ҹ��� �ɱ� �ű��ߴ�...

������ ���� ������ �Ǹ� ������ �ݺ��� �߻��ϴµ� �� �б����� ��Ʈ�̴�.

for(int i=0;i*i<n;i++){
if(n%i==0){
printf("%d %d",i,n/i);
}
}
if(i*i==n){
printf("%d",i)//������ Ȯ��
}
���l �ڵ带 �̿��Ͽ� �پ��� ��� ������ Ǯ ������ ���̴�.

�پ���� �� ���ϱ�
int sum=0;
for(int i=1;i*i<n;i++){
if(n%i==0){
sum+=i;
sum+=n/i;
}
}
if(i*i==n)
sum+=i;

�پ���� �� ���ϱ�
int sum=1;
for(int i=1;i*i<n;i++){
if(n%i==0){
sum*=i;
sum*=n/i;..?�̰͵� �־�� ����!??
}
}
if(i*i==n){
sum*=i;
}
�پ���� ���� ���ϱ�
int sum=0;
for(int i=0;i*i<=n;i++){
if(n%i==0){
sum+=2;
}
}
if(i*i==n)
sum++;
*/