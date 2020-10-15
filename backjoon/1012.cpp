#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

void DFS(int a, int b, vector<vector<int>>&g, vector<vector<bool>>&c) {
	c[a][b] = true;//해당 노드에 왔으니까 true로 체크
	if (b != g[a].size() - 1) {
		int next = g[a][b + 1];
		if (next == 1 && c[a][b + 1] == false) {
			DFS(a, b + 1, g, c);
		}
	}
	if (b != 0) {
		int next3 = g[a][b - 1];
		if (next3 == 1 && c[a][b - 1] == false) {
			DFS(a, b - 1, g, c);
		}
	}
	if (a != g.size() - 1) {
		int next2 = g[a + 1][b];
		if (next2 == 1 && c[a + 1][b] == false) {
			DFS(a + 1, b, g, c);
		}
	}
	if (a != 0) {
		int next4 = g[a - 1][b];
		if (next4 == 1 && c[a - 1][b] == false) {
			DFS(a - 1, b, g, c);
		}
	}
	return;
}

int main() {
	int T, M, N, count;
	cin >> T;
	for (int i = 0;i < T;i++) {
		int value = 0;
		cin >> M >> N >> count;
		vector<vector<int>> g(M, vector<int>(N, 0));
		vector<vector<bool>>c(M, vector<bool>(N, false));
		for (int j = 0;j < count;j++) {
			int a, b;
			cin >> a >> b;
			g[a][b] = 1;

		}
		for (int a = 0;a < M;a++) {
			for (int b = 0;b < N;b++) {
				if (g[a][b] == 1 && c[a][b] == false) {
					DFS(a,b,g,c);
					value++;
				}
			}
		}
		
		cout << value << endl;
		
		
	}

}