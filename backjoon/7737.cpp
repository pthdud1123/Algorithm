#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
int main() {
	ll n, m;

	cin >> n >> m;
	n -= 2;
	vector<ll>arr(n + 1);
	vector<ll>tree(4 * n + 1);

	int size = 1 << (int)log2(n) + 1;
	arr[0] = 1;
	tree[size- 1] = 1;

	for (int i = 1;i <= n;i++) {
		arr[i] = 0;
		for (int j = 0;j < i;j++) {
			arr[i] += ((arr[j] % m)*(arr[i - 1 - j] % m)) % m;
		}
		arr[i] %= m;
		tree[size + i] = arr[i];
	}

	for (int i = size * 2 - 1;i > 1;i -= 2) {
		tree[i / 2] = tree[i] + tree[i - 1];
	}

	ll sum = 0;


	cout << tree[0]%m << endl;
}