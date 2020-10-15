#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

void DFS_NR(int i, int j,int N,char (*g)[101], vector<vector<bool>>&c) {
	c[i][j] = true;
	
	if (j!=N-1&&g[i][j + 1] == 'R'&&c[i][j+1] == false) {
		DFS_NR(i, j + 1,N, g, c);
	}
	if (j !=0&&g[i][j - 1] == 'R'&&c[i][j-1] == false) {
		DFS_NR(i, j - 1,N, g, c);
	}
	if (i != N - 1 && g[i+1][j] == 'R'&&c[i+1][j] == false) {
		DFS_NR(i+1, j,N, g, c);
	}
	if (i != 0&& g[i - 1][j] == 'R'&&c[i - 1][j] == false) {
		DFS_NR(i - 1, j,N, g, c);
	}
	return ;
}
void DFS_NG(int i, int j,int N, char g[][101], vector<vector<bool>>&c) {
	c[i][j] = true;

	if (j != N - 1 && g[i][j + 1] == 'G'&&c[i][j + 1] == false) {
		DFS_NG(i, j + 1,N, g, c);
	}
	if (j != 0 && g[i][j - 1] == 'G'&&c[i][j - 1] == false) {
		DFS_NG(i, j - 1,N, g, c);
	}
	if (i != N-1 && g[i + 1][j] == 'G'&&c[i + 1][j] == false) {
		DFS_NG(i + 1, j,N, g, c);
	}
	if (i != 0 && g[i - 1][j] == 'G'&&c[i - 1][j] == false) {
		DFS_NG(i - 1, j,N, g, c);
	}
	return;
}
void DFS_NB(int i, int j,int N, char g[][101], vector<vector<bool>>&c) {
	c[i][j] = true;

	if (j != N - 1 && g[i][j + 1] == 'B'&&c[i][j + 1] == false) {
		DFS_NB(i, j + 1,N, g, c);
	}
	if (j != 0 && g[i][j - 1] == 'B'&&c[i][j - 1] == false) {
		DFS_NB(i, j - 1,N, g, c);
	}
	if (i != N- 1 && g[i + 1][j] == 'B'&&c[i + 1][j] == false) {
		DFS_NB(i + 1, j,N, g, c);
	}
	if (i != 0 && g[i - 1][j] == 'B'&&c[i - 1][j] == false) {
		DFS_NB(i - 1, j,N, g, c);
	}
	return;
}

void DFS_ADB(int i, int j, int N, char g[][101], vector<vector<bool>>&ad_c) {
	ad_c[i][j] = true;

	if (j != N - 1 && g[i][j + 1] == 'B'&&ad_c[i][j + 1] == false) {
		DFS_ADB(i, j + 1, N, g, ad_c);
	}
	if (j != 0 && g[i][j - 1] == 'B'&&ad_c[i][j - 1] == false) {
		DFS_ADB(i, j - 1, N, g, ad_c);
	}
	if (i != N - 1 && g[i+1][j] == 'B'&&ad_c[i + 1][j] == false) {
		DFS_ADB(i + 1, j, N, g, ad_c);
	}
	if (i != 0 && g[i-1][j] == 'B'&&ad_c[i - 1][j] == false) {
		DFS_ADB(i - 1, j, N, g, ad_c);
	}
	return;
}
void DFS_ADGR(int i, int j, int N, char g[][101], vector<vector<bool>>&ad_c) {
	ad_c[i][j] = true;

	if (j != N - 1 && (g[i][j + 1] == 'G' || g[i][j + 1] == 'R') && ad_c[i][j + 1] == false) {
		DFS_ADGR(i, j + 1, N, g, ad_c);
	}
	if (j != 0 && (g[i][j - 1] == 'G' || g[i][j - 1] == 'R') && ad_c[i][j - 1] == false) {
		DFS_ADGR(i, j - 1, N, g, ad_c);
	}
	if (i != N - 1 && (g[i + 1][j] == 'G' || g[i + 1][j] == 'R') && ad_c[i + 1][j] == false) {
		DFS_ADGR(i + 1, j, N, g, ad_c);
	}
	if (i != 0 && (g[i - 1][j] == 'G' || g[i - 1][j] == 'R') && ad_c[i - 1][j] == false) {
		DFS_ADGR(i - 1, j, N, g, ad_c);
	}
	return;
}
int main() {
	int N;
	int n_value = 0, ad_value = 0;
	cin >> N;
	char g[101][101];
	vector<vector<bool>>c(N, vector<bool>(N,false));
	vector<vector<bool>>ad_c(N, vector<bool>(N, false));
	for (int i = 0;i < N;i++) {
		
		string temp;
		cin >> temp;
		for (int j = 0;j < N;j++) {
			g[i][j] = temp.at(j);
			
		}
	}

	for (int i = 0;i < N;i++) {//Á¤»óÀÎ
		for (int j = 0;j < N;j++) {
			if (g[i][j]=='R'&&c[i][j] == false) {
				DFS_NR(i, j,N, g, c);
				n_value++;
			}
			else if (g[i][j] == 'G'&&c[i][j] == false) {
				DFS_NG(i, j,N, g, c);
				n_value++;
			}
			else if (g[i][j] == 'B'&&c[i][j] == false) {
				DFS_NB(i, j,N, g, c);
				n_value++;
			}
		}
		for (int j = 0;j < N;j++) {
			if ((g[i][j] == 'R' || g[i][j] == 'G') && ad_c[i][j] == false) {
				DFS_ADGR(i, j, N, g, ad_c);
				ad_value++;
			}
			else if (g[i][j] == 'B' && ad_c[i][j] == false) {
				DFS_ADB(i, j, N, g, ad_c);
				ad_value++;
			}
		}
	}
	cout << n_value <<" "<<ad_value<< endl;

}