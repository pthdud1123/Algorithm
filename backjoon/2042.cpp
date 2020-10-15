#include<iostream>
#include<vector>
#include<math.h>

using namespace std;


long long tree[4000000];
long long arr[1000000];




long long sum(int start, int end,int node, int L, int R) {
	//���� �ۿ� �ִ� ���
	if (L >end || start> R) return 0;
	//���� �ȿ� �ִ� ���
	if (L <= start && end <= R) return tree[node];
	//�׷��� ���� ��� ���� ������ �ֱ�
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, L, R) + sum(mid + 1, end, node * 2 + 1, L, R);
}

void update(int start, int end, int node, int index,int value) {
	//���� �ۿ� �ִ� ��� 
	if (index< start || end < index) return;
	//���� �ȿ� ������ �ٸ� ���ҵ� ����
	tree[node] += value;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, value);
	update(mid+1, end, node * 2 + 1, index, value);
}

int main() {
	int N, M, K;//M:������ �Ͼ�� Ƚ��, K:������ ���� ���ϴ� Ƚ��
	
	cin >> N >> M >> K;
	int size = 1<<(int)log2(N) + 1;
	
	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		 tree[size + i]=temp;
		 arr[i+1] = temp;
	}
	
	for (int i=size*2-1;i > 1;i-=2) {

		tree[i / 2] = tree[i] + tree[i - 1];
	}


	for (int i = 0;i < M + K;i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		//a�� 1�ΰ�� b��° ���� c�� �ٲٰ�
		//a�� 2�ΰ�� b��° ������ c��° ������ ���� ���Ͽ� ����ϴ� ���
		if (a == 1) {
			arr[b] = c;
			update(1, size , 1, b, c - tree[b + size - 1]);
		}
		if (a == 2) {
			cout <<sum(1, size , 1, b, c) <<endl;
		}
	}
}