#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

//틀렸던이유 -1이면 돌아가면 안되는데 돌아갔기 때문...
int main() {
	int n=0;//입력받을 수

	
	while (n != -1) {

		scanf("%d", &n);
		if (n == -1)
			break;

		//n이 -1일경우 끝
		int measure[50] = { 0, };//약수들을 저장할 공간
		measure[0] = 1;//모든수는 항상 1을 약수로 가진다.
		int i=2,num=1,sum=1;// n을 나눌수,sum항상 1을 더해주고 있는다.
		//약수 구하기
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
		//약수 알고리즘
	}

	return 0;
}

/*
약수 구하는 프로그램을 c언어로 짰다.
while (i != n) {
if (n%i == 0) {
measure[i] = 1;//약수의 값일경우 1
sum += i;
}
i++;
}
간단하게는 짤수 있지만 느릴것을 예상했다. 

그럼 이것을 어떻게 바꿀 수있을까?
1단계)
for(int i=1;i<=n/2;i++){
if(n%i==0)
printf("%d",i);
}
예를들어 생각을 해보면
10의 약수 ->1,2,5,10이다 
※10을 반으로 나눈것 보다 초과된 값은 절대로 약수가 될 수 없다. ->당연한 소린데 쪼금 신기했다...

일정한 수를 지나게 되면 숫자의 반복이 발생하는데 이 분기점이 루트이다.

for(int i=0;i*i<n;i++){
if(n%i==0){
printf("%d %d",i,n/i);
}
}
if(i*i==n){
printf("%d",i)//제곱수 확인
}
위릐 코드를 이용하여 다앵한 약수 문제를 풀 수있을 것이다.

☆약수의 합 구하기
int sum=0;
for(int i=1;i*i<n;i++){
if(n%i==0){
sum+=i;
sum+=n/i;
}
}
if(i*i==n)
sum+=i;

☆약수의 곱 구하기
int sum=1;
for(int i=1;i*i<n;i++){
if(n%i==0){
sum*=i;
sum*=n/i;..?이것도 있어야 하지!??
}
}
if(i*i==n){
sum*=i;
}
☆약수의 개수 구하기
int sum=0;
for(int i=0;i*i<=n;i++){
if(n%i==0){
sum+=2;
}
}
if(i*i==n)
sum++;
*/