#include<iostream>
#include<string>
using namespace std;
char arr[65][65];
int N;

void DFS(int row, int col,int size) {
	if (size == 1) {
		cout << arr[row][col];
		return;
	}
	bool check = true;
	char pre = -1;
	for (int i = row;i < row + size;i++) {
		for (int j = col;j < col + size;j++) {
			if (pre == -1) {
				pre = arr[i][j];
			}
			else {
				if (pre != arr[i][j]) {
					check = false;
					break;
				}
			}
		}
	}
	if (check) {
		cout << arr[row][col];
	}
	else {
		cout << "(";
		DFS(row, col, size / 2);
		DFS(row, col + size / 2, size / 2);
		DFS(row + size / 2, col, size / 2);
		DFS(row+size/2, col + size / 2, size / 2);
		cout << ")";
	}
	
}
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		string temp;
		cin >> temp;
		for (int j = 0;j < N;j++)arr[i][j] = temp[j];
	}
	
	DFS(0, 0,N);


}