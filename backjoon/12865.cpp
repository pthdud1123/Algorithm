#include<iostream>
#include<algorithm>
using namespace std;
int N, K, W, V;
int arr[101][2];
int dp[100001];
void DP() {
	for (int i = 0;i < N;i++) {
		for (int j = K;j >= 1;j--) {
			if (arr[i][0] <= j) {
				//Ÿ���� �ִ� ���� ¦�� �ִٴ� ���� ��������**->ICT�ڵ� ������ ���
				dp[j] = max(dp[j], dp[j - arr[i][0]] + arr[i][1]);
			}
		}
	}
	cout << dp[K] << endl;
	return;
}
int main() {
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		cin >> W >> V;
		arr[i][0] = W;
		arr[i][1] = V;
	}
	DP();
}