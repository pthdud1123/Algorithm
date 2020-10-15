#include<iostream>
using namespace std;
int min(int a, int b) {
	if (a == 0)return b;
	else
	return a <= b ? a : b;
}
int main() {
	int n, k;
	int arr[101];
	int value[100001];
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	for (int i = 0;i <= k;i++) {
		value[i] = 100001;
	}
	value[0] = 0;
	for (int i = 0;i < n;i++) {
		for (int j = arr[i];j <= k;j++) {
			value[j] = min(value[j], value[j - arr[i]] + 1);
		}
	}

	if (value[k] == 100001)value[k] = -1;
	cout << value[k] << endl;
}