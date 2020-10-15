#include<iostream>
#include<algorithm>
using namespace std;
int n, m, xcnt[1001], ycnt[1001], x, y, res = 2e9;
bool f(int r, int c, int s1, int s2) {
	return !(s1 % 2 ? n - r : r) && !(s2 % 2 ? m - c : c);
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int temp;
			cin >> temp;
			xcnt[i] += temp;
			ycnt[j] += temp;
		}
	}
	for (int i = 0;i < n;i++)x += xcnt[i] % 2;
	for (int i = 0;i < m;i++)y += ycnt[i] % 2;
	if (f(m % 2 ? 0 : x, n % 2 ? 0 : y, y, x))res = min(res,x + m - y);
	if(f(m%2?0:x,n%2?0:))
}