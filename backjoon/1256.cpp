#include<iostream>
#include<vector>
#include<string>

using namespace std;
int N, M, K;
int num = 0;
int result = 1;
int avalue = 1;
int bvalue = 1;
vector<string>arr;
void MAKE(int anum,int znum,string a) {
	if (anum==N&&znum==M) {
		arr.push_back(a);
		return;
	}
	if (anum < N || znum < M) {
		return;
	}
	
		MAKE(anum += 1, znum, a += 'a');
	
		MAKE(anum, znum += 1, a += 'z');
}
int main() {
	cin >> N >> M >> K;
	
	/*for (int i = N + M;i > 0;i--) {
		result *= i;
	}
	for (int i = N;i > 0;i--) {
		avalue *= i;
	}
	for (int i = M;i > 0;i--) {
		bvalue *= i;
	}
	result /= (avalue*bvalue);
	*/
	string a;
	MAKE(0, 0,a);
	cout << arr[K-1] << endl;
}