#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 360000


int main() {
	vector<vector<int>> watch(2,vector<int>(MAX,0));
	int n;
	cin >> n;
	for (int q = 0;q < 2;q++) {
		for (int i = 0;i < n;i++) {
			int index;
			cin >> index;
			watch[q][index] = 1;
		}
	}
	//watch[2]접두사 접미사 체크


	//KMP알고리즘
	

	if (watch[0]== watch[1]) {
		cout << "possible";
	}
	else {
		cout << "impossible";
	}

}