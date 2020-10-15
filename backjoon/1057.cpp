#include<iostream>
#include<cmath>
using namespace std;

//반올림 헤드파일cmath gkatn dnjsgud round();
 int main() {
	double N, K, I;
	int Round = 1;
	cin >> N >> K >> I; 
	while (1) {

		K = round(K / 2);
		I = round(I / 2);
		if (K == I) {
			break;
		}
		else if (K <= 0 || I <= 0) {
			Round = -1;
			break;
		}
		else {
			Round++;
		}
		
	}
	cout << Round;
}