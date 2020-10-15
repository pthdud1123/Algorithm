#include<iostream>
using namespace std;
int dp[1001][11];
int main() {
	int N;
	cin >> N;
	for (int i = 0;i <= 9;i++)dp[1][i] = 1;
	int value = 10;
	for (int i = 0;i <= 9;i++) { dp[2][i] = value;value--; }
	for (int i = 3;i <= N;i++) {
		dp[i][9] = 1;
		for (int j = 8;j >= 0;j--) {
			dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % 10007;
		}
	}
	int sum = 0;
	for (int i = 0;i <= 9;i++) {
		sum += dp[N][i];
		sum %= 10007;
	}
	cout << sum << endl;

}