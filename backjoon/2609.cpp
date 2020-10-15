#include<iostream>
using namespace std;

int mod(int C, int K) {
	if (K == 0) return C;
	else return mod(K, C%K);

}

int main() {
		int K, C;
		cin >> K >> C;
		int T = K > C ? mod(K, C) : mod(C, K);
		int t = T * (K / T)*(C / T);
		cout <<T << endl<<t;
}