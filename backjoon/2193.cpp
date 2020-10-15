#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	long long  dp[91][2] = {0,};//인덱스 번호가 
	dp[1][1] = 1;
	dp[1][0] = 0;
	for (int i = 2;i <= N;i++) {
		if (dp[i-1][0] != 0) {
			dp[i][1] = dp[i - 1][0];
			dp[i][0] = dp[i - 1][0];
		}
		if (dp[i - 1][1] != 0)dp[i][0] += dp[i - 1][1];
	}
	cout << dp[N][1] + dp[N][0] << endl;

}