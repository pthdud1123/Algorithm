//������ �� ���ϱ�->���׸�Ʈ Ʈ��
//�迭�� Ʈ���� �̿��ϴµ�
//���� ó���� 1<<(int)log2(N)+1�̷��� size����ִ� ����� ��������.
//�׷��� �ʹ� �����߾���.
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