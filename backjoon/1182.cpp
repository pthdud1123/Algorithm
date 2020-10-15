#include<iostream>

using namespace std;

int N, S;
int cnt = 0;
int arr[20];

void DFS(int k, int sum) {
	int s = sum + arr[k];
	if (k == N) {
		return;
	}
	if (s == S) {
		cnt++;
	}
	DFS(k + 1, s);
	DFS(k + 1, sum);
}
int main() {
	cin >> N >> S;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	DFS(0, 0);
	cout << cnt;
}