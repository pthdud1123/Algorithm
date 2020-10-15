#include<iostream>
#include<stdlib.h>
using namespace std;
int n;
int M(int a, int b) {
	return a >= b ? a : b;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0;t < T;t++) {
		cin >> n;
	
		int **arr = (int**)malloc(sizeof(int)*2);
		int **save_S = (int**)malloc(sizeof(int) * 2);
		for (int i = 0;i < 2;i++) {
			arr[i] = (int*)malloc(sizeof(int)*n);
			save_S[i] = (int*)malloc(sizeof(int)*(n+1));
		}

		
		for (int K = 0;K < 2;K++) {
			for (int k = 1;k <= n;k++) {
				cin >> arr[K][k];
			}
		}
		//위에 줄부터 시작
		save_S[0][0] = 0;
		save_S[1][0] = 0;
		save_S[0][1] = arr[0][1];
		save_S[1][1] = arr[1][1];
		
		for (int i = 2;i <= n;i++) {
			save_S[0][i] = M(save_S[1][i - 1], save_S[1][i - 2]) + arr[0][i];
			save_S[1][i] = M(save_S[0][i - 1], save_S[0][i - 2]) + arr[1][i];

		}
		cout << M(save_S[0][n],save_S[1][n]) << endl;
	}
}