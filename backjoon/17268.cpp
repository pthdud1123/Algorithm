#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define mod 987654321

int main() {
	int N;cin >> N;
	N /= 2;
	vector<ll> arr(N+1); //ll숫자 범위 주의
	arr[0] = 1;
	for (int i = 1;i <= N;i++) {
		arr[i] = 0;
		for (int j = 0;j < i;j++) {
			arr[i] += ((arr[j] % mod)*(arr[i - 1 - j] % mod)) % mod;
		}
		arr[i] %= mod;
	}
	cout << arr[N] % mod << endl;
}