#include<stdio.h>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

/*int factorial(int N,int P,int value) {

	if (N == 1) {
		value += 1;
		return value % P;
	}
	value += (N%P);
	N--;
	factorial(N, P, value);

}*/
int main() {
	long long N, P,value=1,result;
	cin >> N >> P;
	
	for (long long i = 1;i <= N;i++) {
		value *= i;
		if (value >= P) {
			value %= P;
		}
	}
	//���丮���� ���� ũ�� ������ �߰��߰��� ��� ��������� �Ѵ�.
	
	value %= P;
	cout << value;

}


/*
���丮��
1.�Լ��� �����ϱ�->���� �̹�� �� ����
long long factorial(long long N) {
int value = 1;
for (int i = 2;i <= N;i++) {
value *= i;
}
return value;
}
2.����� �� �̿��ϱ�
int factorial (int a){
if(a<=1) reutrn 1;
//���� �Ű������� �Ѿ�� ���� 1�� �ٿ������鼭 �ٽ� �ڽ��� ȣ���Ѵ�.
//���� ��� 5�� �Ѿ� ���� 5*factorial(4)��� �����Ѵ� ->4*factorial(3)==>5*4*3*2*1
return a* factorial(a-1);
}

3.�Լ��� ��������ʰ� �����ϱ� 
for(int i=1;i<=n;i++){
//���ܰ躰�� ���� �ʱ�ȭ �Ѵ�.
result=1;
//i �� ���� ���丮�� ���� ���Ѵ�.
for(int j=2;j<=i;j++) result*=j;
//i�� ���� ���丮�� ���� ����Ѵ�.
printf("%2d!=%d\n",i,result);
}

4. �� ��� ȿ�������� ������ ��� 
->���� ������ ��� ���� ����� result���� 1�� �ʱ�ȭ ���� �ʰ� �״�� ��� �ϸ� j ������ ����ϴ�
�ι�° for ���� ��� ���� �ʰ� ���丮�� ���� �������� ���ִ�. 
int i,result=1;
for(int i=1;i<=n;i++){
reuslut*=i;
}
return 0;
}

==>�������� �� ���丮���� ������ �ƴѰ� ����.
���丮���� ���� Ŀ������ ���ϱ� �������� Ŀ���⶧���� ū �� ���� ���� �Ҽ��� �������� �ʿ��� ��ŭ N,P���� ���� �����
���߿� �ٽ� �����ִ°� ��� ������?
->��� �Ҽ��� �������� ��� �ڸ� ���� ���� �ΰ� ����.

�Ҽ����ϱ� ������ �˰���
->..�� ���ʿ� �Ұ� ����.
*/