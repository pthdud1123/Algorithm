#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int N;
int card[1002];
int value[1002];
int M(int a, int b) {
	return a > b ? a : b;
}
int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> card[i];//i�� ī���� �����̰� ,���� ī�尪
	}
	/*for (int i = 1;i <= N;i++) {
		value[i] = M(card[i] * (N / i) + card[N%i], card[i] + card[N - i]);
	}
	sort(value, value + N + 1);*/
	//ī�尡 �����϶� ~N���϶������� ��
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= i;j++) {
			value[i] = M(value[i], value[i - j] + card[j]);
		}
	}
	
	cout << value[N] << endl;
}
/*
10
1 100 160 1 1 1 1 1 1 1
520*/