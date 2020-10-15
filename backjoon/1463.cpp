#include<iostream>
#include<algorithm>
#define MAX 1000001

using namespace std;

void  main() {
	int N, dp[MAX];
	cin >> N;
	fill(dp, dp + MAX, 1000000000);
	dp[1] = 0;
	for (int i = 1;i < N;i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i * 2 < MAX)dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		if (i * 3 < MAX)dp[i * 3] = min(dp[i * 2], dp[i] + 1);
	}
	cout << dp[N] << endl;
}