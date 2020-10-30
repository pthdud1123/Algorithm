#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int cube[201][201][201];
int main() {
	ifstream inp("cube.inp");
	ofstream out("cube.out");
	int T;

	inp >> T;

	for (int n = 0; n < T; n++) {
		int arr[3];
		inp >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		
		for (int i = 1; i <= arr[0]; i++) {
			for (int j = 1; j <= arr[1]; j++) {
				for (int k = 1; k <= arr[2]; k++) {
					if (i == j && j == k) {
						cube[i][j][k] = 1;
					}
					else if (i == 1) {
						cube[i][j][k] = j * k;
					}
					else if (j == 1) {
						cube[i][j][k] = i * k;
					}
					else if (k == 1) {
						cube[i][j][k] = j * i;
					}
					else {
						cube[i][j][k] = cube[1][j][k] + cube[i - 1][j][k];
						for (int x = 2; x <= ceil(i/2); x++) {
							if (cube[x][j][k] + cube[i - x][j][k] < cube[i][j][k]) {
								cube[i][j][k] = cube[x][j][k] + cube[i - x][j][k];
							}
						}
						for (int x = 1; x <= ceil(j / 2); x++) {
							if (cube[i][x][k] + cube[i][j-x][k] < cube[i][j][k]) {
								cube[i][j][k] = cube[i][x][k] + cube[i][j - x][k];
							}
						}
						for (int x = 1; x <= ceil(k / 2); x++) {
							if (cube[i][j][x] + cube[i][j ][k - x] < cube[i][j][k]) {
								cube[i][j][k] = cube[i][j][x] + cube[i][j][k - x];
							}
						}
					}
					
				}
			}
			
		}
		
		
		out << cube[arr[0]][arr[1]][arr[2]] << endl;
	}
}