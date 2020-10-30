#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
bool one[101][101][101];
bool two[101][101][101];
bool three[101][101][101];


bool wincheck_one(int a, int b, int c) {
	if (a - 2 >= 0 && !two[a - 2][b][c])return true;
	if (a - 3 >= 0 && !three[a - 3][b][c])return true;
	else  {
		if (b - 2 >= 0) {
			if (b - 2 < a) {
				if (!two[b - 2][a][c])return true;
			}
			else {
				if (!two[a][b - 2][c])return true;
			}
		}
		if (b - 3 >= 0) {
			if (b - 3 < a) {
				if (!three[b - 3][a][c])return true;
			}
			else {
				if (!three[a][b - 3][c])return true;
			}
		}
		if (c - 2 >= 0) {
			if (c - 2 < b) {
				if (c - 2 < a) {
					if (!two[c - 2][a][b])return true;
				}
				else {
					if (!two[a][c - 2][b])return true;
				}
			}
			else {
				if (!two[a][b][c - 2])return true;
			}
		}
		if (c - 3 >= 0) {
			if (c - 3 < b) {
				if (c - 3 < a) {
					if (!three[c - 3][a][b])return true;
				}
				else {
					if (!three[a][c - 3][b])return true;
				}
			}
			else {
				if (!three[a][b][c - 3])return true;
			}
		}
	}
	
	return false;
}
bool wincheck_two(int a, int b, int c) {
	if (a - 1 >= 0 && !one[a - 1][b][c])return true;
	if (a - 3 >= 0 && !three[a - 3][b][c])return true;
	else {
		if (b - 1 >= 0) {
			if (b - 1 < a) {
				if (!one[b - 1][a][c])return true;
			}
			else {
				if (!one[a][b - 1][c])return true;
			}
		}
		if (b - 3 >= 0) {
			if (b - 3 < a) {
				if (!three[b - 3][a][c])return true;
			}
			else {
				if (!three[a][b - 3][c])return true;
			}
		}
		if (c - 1 >= 0) {
			if (c - 1 < b) {
				if (c - 1 < a) {
					if (!one[c - 1][a][b])return true;
				}
				else {
					if (!one[a][c - 1][b])return true;
				}
			}
			else {
				if (!one[a][b][c - 1])return true;
			}
		}
		if (c - 3 >= 0) {
			if (c - 3 < b) {
				if (c - 3 < a) {
					if (!three[c - 3][a][b])return true;
				}
				else {
					if (!three[a][c - 3][b])return true;
				}
			}
			else {
				if (!three[a][b][c - 3])return true;
			}
		}
	}
	return false;
}
bool wincheck_three(int a, int b, int c) {
	if (a - 2 >= 0 && !two[a - 2][b][c])return true;
	if (a - 1 >= 0 && !one[a - 1][b][c])return true;
	else {
		if (b - 2 >= 0) {
			if (b - 2 < a) {
				if (!two[b - 2][a][c])return true;
			}
			else {
				if (!two[a][b - 2][c])return true;
			}
		}
		if (b - 1 >= 0) {
			if (b - 1 < a) {
				if (!one[b - 1][a][c])return true;
			}
			else {
				if (!one[a][b - 1][c])return true;
			}
		}
		if (c - 2 >= 0) {
			if (c - 2 < b) {
				if (c - 2 < a) {
					if (!two[c - 2][a][b])return true;
				}
				else {
					if (!two[a][c - 2][b])return true;
				}
			}
			else {
				if (!two[a][b][c - 2])return true;
			}
		}
		if (c - 1 >= 0) {
			if (c - 1 < b) {
				if (c - 1 < a) {
					if (!one[c - 1][a][b])return true;
				}
				else {
					if (!one[a][c - 1][b])return true;
				}
			}
			else {
				if (!one[a][b][c - 1])return true;
			}
		}
	}
	return false;
}

int main() {
	ifstream inp("coin.inp");
	ofstream out("coin.out");

	int T;
	inp >> T;
	for (int n = 0; n < T; n++) {
		int arr[3];
		inp >> arr[0] >> arr[1] >> arr[2];
		int temp[3];
		temp[0] = arr[0], temp[1] = arr[1], temp[2] = arr[2];
		sort(arr, arr + 3);
		//뽑기전 이러한 상태일때 엘리스는 이긴다.
		//1개를 x			2개를 x				3개를 x
		one[0][0][0] = true, two[0][0][0] = true, three[0][0][0] = true;
		one[0][0][1] = false, two[0][0][1] = false, three[0][0][1] = false;
		one[0][0][2] = false, two[0][0][2] = true, three[0][0][2] = true;
		one[0][0][3] = true, two[0][0][3] = true, three[0][0][3] = true;
		//한가지라도 false가 나오면 true를 해준다.



		for (int i = 0; i <= arr[0]; i++) {
			for (int j = i; j <= arr[1]; j++) {
				for (int k = j; k <= arr[2]; k++) {
					if (i==0&&j==0&&k<=3) {
						continue;
					}
					else {
						one[i][j][k] = wincheck_one(i, j, k);
						two[i][j][k] = wincheck_two(i, j, k);
						three[i][j][k] = wincheck_three(i, j, k);
					}
				}
			}
		}
		int result=-1;
		if (one[arr[0]][arr[1]][arr[2]] || two[arr[0]][arr[1]][arr[2]] || three[arr[0]][arr[1]][arr[2]]) {
			result = 1;
		}
		
		out << "(" << temp[0] << " " << temp[1] << " " << temp[2] << ") : " << result << endl;
	}
}