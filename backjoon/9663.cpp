#include<iostream>
#include<math.h>
using namespace std;
int N, cnt = 0;
int Q[15];
bool possible(int row) {
	for (int j = 0;j < row;j++) {
		int value = int (abs(Q[row] - Q[j]));
		if ( (Q[row] == Q[j]) || value == (row - j) ) {
			return false;
		}
	}
	return true;
}
void DFS(int a) {
		if (a == N) {
			cnt++;
			return;
		}
		else {
			for (int  i = 0;i < N;i++) {
				Q[a] = i;
				if (possible(a)) {
					DFS(a + 1);
				}
				
			}

		}
	
}
int main() {
	cin >> N;
	DFS(0);
	cout << cnt << endl;
}