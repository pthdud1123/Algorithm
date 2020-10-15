#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	long long n, w;//n:요일 수 ,w:초기현금
	long long coin=0;//코인 개수
	int bytecoin[16];
	bool buy = false;//아직 안삼
	cin >> n >> w;
	for (int i = 1;i <= n;i++) {
		cin >> bytecoin[i];
	}
	for (int i = 1;i <= n;i++) {
		if (i != n && bytecoin[i] < bytecoin[i + 1] && buy == false) {
			coin = w / bytecoin[i];//코인사기
			w -= coin * bytecoin[i];//코인 사고 남은 돈
			buy = true;//샀음을 알린다.
		}
		if (i!=n&&buy == true && bytecoin[i] > bytecoin[i + 1]) {
			w += coin * bytecoin[i];
			coin = 0;
			buy = false;//팔았다~
		}
		if (i == n&&buy==true) {
			w += coin * bytecoin[i];
		}
	}
	cout << w;

}