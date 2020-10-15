#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

//ceil()함수는 소수점 자리의 숫자를 무조건 올리는 함수이다.
//floor()함수는 뜻그대로 바닥으로 만든다. 소수점 아래를 무시

//알고리즘 분석
/*1.이분탐색을 이용한풀이->당연히 start와end를 지정하고 mid를 찾아가며 답을 찾아내면 된다.
2.수학적풀이->root값의 제곱이 답보다 작다면+1한 값이 정답이 될것이다.
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