#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
static int temp;

int DFS(int N, int M,int temp, vector<vector<int>>&g, vector<vector<bool>>&c) {
	temp++;
	c[N][M] = true;// 체크한 노드
	if (M != g[N].size() - 1) {
		if (g[N][M + 1] == 1 && c[N][M + 1] == false) {
			temp=DFS(N, M + 1, temp, g, c);
		}
	}
	if (M != 0) {
		if (g[N][M - 1] == 1 && c[N][M - 1] == false) {
			temp=DFS(N, M - 1, temp, g, c);
		}
	}
	
	if (N != g.size() - 1) {
		if (g[N + 1][M] == 1 && c[N + 1][M] == false) {
			temp=DFS(N + 1, M, temp, g, c);

		}
	}

	if (N !=0) {
		if (g[N - 1][M] == 1 && c[N - 1][M] == false) {
			temp=DFS(N - 1, M, temp, g, c);

		}
	}
	
	return temp;
}

int main() {
	int N, M, K;
	int size = 0;
	cin >> N >> M >> K;
	N++;M++;
	vector<vector<int>>g(N, vector<int>(M,0));
	vector<vector<bool>>c(N, vector<bool>(M, false));
	for (int i = 0;i < K;i++) {
		int r, c;
		cin >> r >> c;
		g[r][c] = 1;//쓰레기가 있는 곳을 1로 체크
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (g[i][j] == 1 && c[i][j] == false) {
				 temp = 0;
				 temp=DFS(i, j,temp, g, c);
				if (temp > size) {
					size = temp;
				}
			}
		}
	}

	cout << size << endl;
}