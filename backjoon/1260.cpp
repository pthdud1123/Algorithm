#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	vector<vector<int>>g(N);
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		g[a].pop_back(b);
	}

}
