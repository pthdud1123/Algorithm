#include<iostream>
#include<math.h>
using namespace std;
int dp[100001];
int N, cnt = 0;
int min(int a, int b) { 
	return a <= b ? a : b; }
int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		dp[i] = 999999;
	}
	dp[0]=-1,dp[1] = 1, dp[2] = 2, dp[3] = 3;
	for (int i = 4;i <= N;i++) {
		for (int j = 1;j*j <= i;j++) {
			if (j*j == i)dp[i] = i / (j*j);
			else
				dp[i] = min(dp[i], dp[j*j] + dp[i -( j*j)]);
		}
	}
	cout << dp[N] << endl;
}