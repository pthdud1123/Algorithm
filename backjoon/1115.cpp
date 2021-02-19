#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int N;
int P[51];//입력받는 값
int T[51];//비교하는 값
int masterkey = false;
int MIN = 999;

void  swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_arr() {
	bool checklist[51];
	bool key = true;
	checklist[0] = false;
	int v = P[0];
	int min = 0;
	for (int i = 1;i < N;i++) {
		if (checklist[v]) {
			checklist[v] = false;
			v = P[v];
			continue;
		}
		else {
			key = false;
			break;
		}
	}
	if (key) {

		for (int i = 0;i < N;i++) {
			//cout << P[i];
			if (T[i] != P[i]) {
				min++;
			}
		}
		if (MIN > min) {
			MIN = min;
		}
		
		//masterkey = true;
	}
		
}
void permutation(int n,int r) {
	//탈출조건으로 r이 0이 되면 순열의 한경우가 완료 되엇으므로 return 합니다. 
	
	if (r == 0) {
		
			print_arr();
			return;
	}
	//가장 끝에 있는 n-1의 위치의 원소와 현재보고 있는 ㅑ의 원소를 바꾸어서 재귀함수에 넣어준다.
	//1-2-3을 예로들면 3과 3을 바꾼다.->이것은 고정값.
	//그러면 
	for (int i = N - 1;i >= 0;i--) {
		//if (!masterkey) {
			swap(&P[i], &P[N - 1]);
			permutation(n - 1, r - 1);
			swap(&P[i], &P[N - 1]);
		/*}
		else {
			return;
		}*/
	}
}

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> P[i];
		T[i] = P[i];
	}
	
	int k = P[0];
	bool mk = true;
	bool minicheck[51];
	for (int i = 1;i < N;i++) {
		if (minicheck[k]) {
			minicheck[k] = false;
			k = P[k];
			continue;
		}
		else {
			mk = false;
			permutation(N,N);
			break;
		}
	}
	if (mk) {
		cout << 0;
	}
	else {
		cout << MIN;
	}

	
	return 0;
}

/*int main() {
	
	int T[51];//기존의 값
	
	int Min = 9999;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> P[i];
		T[i] = P[i];
	}

	
	//sort(P, P + N);
	//입력값이 완벽순열이 아닌경우
	do {
		bool key = true;
		bool p[51] = {1,};//완벽순열인지 체크하기 위하여
		int c[51];
		p[0] = true;//인덱스0은 일단 무조건 포함.
		c[0] = 0;
		int count = 0;
		for (int i = 1;i < N;i++) {
			c[i] = P[c[i - 1]];
			if (!p[c[i]]) {
				p[c[i]] = true;
				
			}
			else {
				key = false;
				break;
			}
		}
		if (key) {
			for (int i = 0;i < N;i++) {
				count += abs(T[i] - P[i]);
			}
			if (Min > count) {
				Min = count;
			}
		}
		
		
		
	} while (next_permutation(P, P + N));
	
	cout << Min << endl;
	

}
	*/
//일단 순열의 문제에서 next_permutation은 모든 경우의 수를 구할 수는 있지만
//시간이 엄~~~~~~~~~~~~~~~~~~~~~~~~~청 걸린다 51!한다고 자체가 미친짓인데 다른 방법을 찾아야 함
//=>재귀함수와 체크리스트를 사용하여 풀어보자!
