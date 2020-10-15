#include<iostream>
#include<time.h>
#include<vector>
#include<math.h>
using namespace std;

void getChe1(int num) {
	int *arr;
	arr = (int *)malloc(sizeof(int)*num);
	for (int i = 2;i <= num;i++) {
		arr[i] = i;
	}
	for (int i = 2;i <= sqrt(num);i++) {
		if (arr[i] == 0)continue;
		for (int j = i + i;j <= num;j += i) {
			arr[j] = 0;
		}
	}
	for (int i = 2;i <= num;i++) {
		if (arr[i] != 0) {
			cout << arr[i] << " ";
		}
	}
}
int main() {
	clock_t start, end;
	start = clock();
	getChe1(50000);
	end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "playtime:" << time;
}