#include<iostream>//DFS
using namespace std;
int N;
int cnt = 0;
int arr[18][18];
//R:오른쪽(H상태일떄 만 가능),C:대각선,D:아래(V상태 일떄만 가능)
void DFS(int row, int col,char state) {
	if (row == N-1 && col == N-1) {
		cnt++;
		return;
	}
	if (state == 'H') {
		//오른쪽으로 이동할려 할때
		if (col < N&&arr[row][col + 1] != 1) DFS(row, col + 1, 'H');
		//대각선으로 이동할때
		if (row < N&&col < N&&arr[row + 1][col + 1] != 1 && arr[row][col + 1] != 1 && arr[row + 1][col] != 1)DFS(row + 1, col + 1, 'D');
	}
	if (state == 'D') {
		//오른쪽
		if (col < N&&arr[row][col + 1] != 1) DFS(row, col + 1, 'H');
		//아래
		if (row < N&&arr[row+1][col] != 1) DFS(row+1, col, 'V');
		//대각선
		if (row < N&&col < N&&arr[row + 1][col + 1] != 1 && arr[row][col + 1] != 1 && arr[row + 1][col] != 1)DFS(row + 1, col + 1, 'D');
	}
	if (state == 'V') {
		//아래
		if (row < N&&arr[row + 1][col] != 1) DFS(row + 1, col, 'V');
		//대각선
		if (row < N&&col < N&&arr[row + 1][col + 1] != 1 && arr[row][col + 1] != 1 && arr[row + 1][col] != 1)DFS(row + 1, col + 1, 'D');
	}
}
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}
	char state = 'H';//H:가로,V:세로,D:대각선
	DFS(0, 1,state);
	cout << cnt << endl;
}