#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int N;
int P[51];//�Է¹޴� ��
int T[51];//���ϴ� ��
int masterkey = false;
int MIN = 999;

void  swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_arr() {
	bool checklist[51];
	bool key = true;
	checklist[0] = false;
	int v = P[0];
	int min = 0;
	for (int i = 1;i < N;i++) {
		if (checklist[v]) {
			checklist[v] = false;
			v = P[v];
			continue;
		}
		else {
			key = false;
			break;
		}
	}
	if (key) {

		for (int i = 0;i < N;i++) {
			//cout << P[i];
			if (T[i] != P[i]) {
				min++;
			}
		}
		if (MIN > min) {
			MIN = min;
		}
		
		//masterkey = true;
	}
		
}
void permutation(int n,int r) {
	//Ż���������� r�� 0�� �Ǹ� ������ �Ѱ�찡 �Ϸ� �Ǿ����Ƿ� return �մϴ�. 
	
	if (r == 0) {
		
			print_arr();
			return;
	}
	//���� ���� �ִ� n-1�� ��ġ�� ���ҿ� ���纸�� �ִ� ���� ���Ҹ� �ٲپ ����Լ��� �־��ش�.
	//1-2-3�� ���ε�� 3�� 3�� �ٲ۴�.->�̰��� ������.
	//�׷��� 
	for (int i = N - 1;i >= 0;i--) {
		//if (!masterkey) {
			swap(&P[i], &P[N - 1]);
			permutation(n - 1, r - 1);
			swap(&P[i], &P[N - 1]);
		/*}
		else {
			return;
		}*/
	}
}

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> P[i];
		T[i] = P[i];
	}
	
	int k = P[0];
	bool mk = true;
	bool minicheck[51];
	for (int i = 1;i < N;i++) {
		if (minicheck[k]) {
			minicheck[k] = false;
			k = P[k];
			continue;
		}
		else {
			mk = false;
			permutation(N,N);
			break;
		}
	}
	if (mk) {
		cout << 0;
	}
	else {
		cout << MIN;
	}

	
	return 0;
}

/*int main() {
	
	int T[51];//������ ��
	
	int Min = 9999;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> P[i];
		T[i] = P[i];
	}

	
	//sort(P, P + N);
	//�Է°��� �Ϻ������� �ƴѰ��
	do {
		bool key = true;
		bool p[51] = {1,};//�Ϻ��������� üũ�ϱ� ���Ͽ�
		int c[51];
		p[0] = true;//�ε���0�� �ϴ� ������ ����.
		c[0] = 0;
		int count = 0;
		for (int i = 1;i < N;i++) {
			c[i] = P[c[i - 1]];
			if (!p[c[i]]) {
				p[c[i]] = true;
				
			}
			else {
				key = false;
				break;
			}
		}
		if (key) {
			for (int i = 0;i < N;i++) {
				count += abs(T[i] - P[i]);
			}
			if (Min > count) {
				Min = count;
			}
		}
		
		
		
	} while (next_permutation(P, P + N));
	
	cout << Min << endl;
	

}
	*/
//�ϴ� ������ �������� next_permutation�� ��� ����� ���� ���� ���� ������
//�ð��� ��~~~~~~~~~~~~~~~~~~~~~~~~~û �ɸ��� 51!�Ѵٰ� ��ü�� ��ģ���ε� �ٸ� ����� ã�ƾ� ��
//=>����Լ��� üũ����Ʈ�� ����Ͽ� Ǯ���!
