#include<iostream>
#include<fstream>
using namespace std;

int main() {

    ifstream inp("addingways.inp");
    ofstream out("addingways.out");
    int n, k;

    inp >> n >> k;
    while (n != 0 && k != 0) {
        int dp[301][301] = { 0, };

        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (j == 1 || i == j)dp[i][j] = 1;
                else {
                    for (int t = 1; t <= j; t++) {
                        dp[i][j] += dp[i - j][t];
                        dp[i][j] %= 1000000007;
                    }
                }
            }
        }
        dp[n][k] %= 1000000007;
        out << dp[n][k] << endl;
        inp >> n >> k;

    }

    return 0;

}