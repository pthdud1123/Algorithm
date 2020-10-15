#include<iostream>
#include<vector>
#include<math.h>

using namespace std;


long long tree[4000000];
long long arr[1000000];




long long sum(int start, int end,int node, int L, int R) {
	//범위 밖에 있는 경우
	if (L >end || start> R) return 0;
	//범위 안에 있는 경우
	if (L <= start && end <= R) return tree[node];
	//그렇지 않은 경우 범위 나누어 주기
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, L, R) + sum(mid + 1, end, node * 2 + 1, L, R);
}

void update(int start, int end, int node, int index,int value) {
	//범위 밖에 있는 경우 
	if (index< start || end < index) return;
	//범위 안에 있으면 다른 원소도 갱신
	tree[node] += value;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, value);
	update(mid+1, end, node * 2 + 1, index, value);
}

int main() {
	int N, M, K;//M:변경이 일어나는 횟수, K:구간의 합을 구하는 횟수
	
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
		//a가 1인경우 b번째 수를 c로 바꾸고
		//a가 2인경우 b번째 수부터 c번째 수까지 합을 구하여 출력하는 방법
		if (a == 1) {
			arr[b] = c;
			update(1, size , 1, b, c - tree[b + size - 1]);
		}
		if (a == 2) {
			cout <<sum(1, size , 1, b, c) <<endl;
		}
	}
}