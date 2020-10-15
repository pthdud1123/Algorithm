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
	//팩토리얼의 수가 크기 때문에 중간중간에 계속 나누어줘야 한다.
	
	value %= P;
	cout << value;

}


/*
팩토리얼
1.함수로 구현하기->나는 이방법 을 했음
long long factorial(long long N) {
int value = 1;
for (int i = 2;i <= N;i++) {
value *= i;
}
return value;
}
2.재귀함 수 이용하기
int factorial (int a){
if(a<=1) reutrn 1;
//현재 매개변수로 넘어온 값을 1씩 줄여나가면서 다시 자신을 호출한다.
//예를 들어 5가 넘어 오면 5*factorial(4)라고 연산한다 ->4*factorial(3)==>5*4*3*2*1
return a* factorial(a-1);
}

3.함수를 사용하지않고 구현하기 
for(int i=1;i<=n;i++){
//각단계별로 값을 초기화 한다.
result=1;
//i 에 대한 팩토리얼 값을 구한다.
for(int j=2;j<=i;j++) result*=j;
//i에 대한 팩토리얼 값을 출력한다.
printf("%2d!=%d\n",i,result);
}

4. 위 답안 효과적으로 숭정한 답안 
->좋은 점수를 얻기 위한 답안은 result값을 1로 초기화 하지 않고 그대로 사용 하면 j 변수를 사용하는
두번째 for 문을 사용 하지 않고 팩토리얼 값을 계속출력할 수있다. 
int i,result=1;
for(int i=1;i<=n;i++){
reuslut*=i;
}
return 0;
}

==>생각했을 떄 팩토리얼의 문제가 아닌것 같다.
팩토리얼은 수가 커질수록 기하급 수적으로 커지기때문에 큰 수 같은 경우는 소수를 기준으로 필요한 만큼 N,P에서 값을 덜어내고
나중에 다시 더해주는게 방법 일지도?
->어떻게 소수를 기준으로 잡아 자를 지가 문제 인거 같다.

소수구하기 최적의 알고리즘
->..도 안필요 할거 같다.
*/