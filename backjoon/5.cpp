//구간의 합 구하기->세그먼트 트리
//배열로 트리를 이용하는데
//나는 처음에 1<<(int)log2(N)+1이렇게 size잡아주는 방법을 몰랐었다.
//그래서 너무 막막했었다.
#include<iostream>
#include<vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	priority_queue<int, vector<int> ,greater<int> >q;
	int n,num;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num;
		q.push(num);
	}
	for (int i = 0;i < n*n - n;i++) {
		cin >> num;
		if (num > q.top()) {
			q.pop();
			q.push(num);
		}
	
	}
	cout << q.top();

}