#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
bool DFS(int start,int j, int(*g),bool(*check),bool test) {
	
	
	check[j] = true;
	if (start == g[j]) {
		test = true;
	}
	else if (j == g[j]&&start!=j) {
		test = false;//ÆÀ¿¡ ³¢ÀÌÁö ¸øÇÑ °æ¿ì
	}
	else if (check[g[j]]==false) {
		int a = g[j];
		test=DFS(start,a, g, check,test);

	}
	else {
		test = false;
	}
	
	
	return test;
	
}

int main() {
	int T, N;
	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> N;
		int g[100000];
		bool student[100000] = { false, };
		bool check[10000] = { false, };
		

		int result = 0;
		for (int j = 0;j < N;j++) {
			int v;
			cin >> v;
			v -= 1;
			g[j]=v;
		}

		for (int j = 0;j < N;j++) {
			bool test = false;
			test = DFS(j,j, g, check,false);
			
			if(!test) {
				result += 1;
			}
			
			
			if (!test)
				student[j] = true;
			if (test) {
				student[j] = true;
				while (1) {
					int temp = g[j];
					if (temp == j)
						break;
					else {
						student[temp] = true;
					}
				}
			}
			for (int k = 0;k < N;k++) {
				if (student[k] != true)
					check[k] = false;
			}
			
			
		}
		cout << result << endl;
	}
	return 0;
	
}