#include<iostream>//DFS
using namespace std;
int N;
int cnt = 0;
int arr[18][18];
//R:������(H�����ϋ� �� ����),C:�밢��,D:�Ʒ�(V���� �ϋ��� ����)
void DFS(int row, int col,char state) {
	if (row == N-1 && col == N-1) {
		cnt++;
		return;
	}
	if (state == 'H') {
		//���������� �̵��ҷ� �Ҷ�
		if (col < N&&arr[row][col + 1] != 1) DFS(row, col + 1, 'H');
		//�밢������ �̵��Ҷ�
		if (row < N&&col < N&&arr[row + 1][col + 1] != 1 && arr[row][col + 1] != 1 && arr[row + 1][col] != 1)DFS(row + 1, col + 1, 'D');
	}
	if (state == 'D') {
		//������
		if (col < N&&arr[row][col + 1] != 1) DFS(row, col + 1, 'H');
		//�Ʒ�
		if (row < N&&arr[row+1][col] != 1) DFS(row+1, col, 'V');
		//�밢��
		if (row < N&&col < N&&arr[row + 1][col + 1] != 1 && arr[row][col + 1] != 1 && arr[row + 1][col] != 1)DFS(row + 1, col + 1, 'D');
	}
	if (state == 'V') {
		//�Ʒ�
		if (row < N&&arr[row + 1][col] != 1) DFS(row + 1, col, 'V');
		//�밢��
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
	char state = 'H';//H:����,V:����,D:�밢��
	DFS(0, 1,state);
	cout << cnt << endl;
}