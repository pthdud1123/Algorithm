#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

vector<int> RabinKarp(string S, string W,string A) {
	vector<int> shift;//��ȯ�� ����Ʈ ��
	int Ssize = S.size(), Wsize = W.size();
	int whash=0,shash=0;
	//W�ؽð� ���ϱ�
	for (int i = 0,j=0;i < Wsize;i++) {
		whash = whash + A[W[Wsize - 1 - i]-1] * pow(2, j);
		j++;
	}
	//�� �ؽ� �� ���ؼ� W�ؽ� ���� ���ϱ�
	for (int k = 1;k < Wsize;k++) {//k�� �̵��� ����Ʈ���� �������� �ִ� �� üũ
		shash = 0;
		for (int i = 0;i < Ssize;i++) {
			S[i]++;
			if (S[i] > Wsize)
				S[i] = 1;
		}

		for (int i = 0;i < Ssize-Wsize;i++) {
			if (i == 0) {
				for (int j = 0;j < Wsize;j++) {
					shash = shash + A[S[Wsize - j - 1] - 1] * pow(2, j);
				}
			}
			else {
				//������ =2*(���� �ؽ� �� - ���� ���ڿ� �� ���ڸ�(a))-���� �߰� �Ǵ� ���ڸ� ����(b).
				int a = A[S[i - 1]-1] * pow(2, Wsize - 1);
				int b = A[S[i + Wsize - 1]-1] * pow(2, 0);
				shash = 2 * (shash - a) + b;
			}
			if (shash == whash) {
				//�ؽ����� �´ٸ� ���� ���� �´��� Ȯ�����ֱ�
				bool key = true;
				for (int x = i,y=0;x < Wsize;x++,y++) {
					if (S[x] != W[y]) {
						key = false;
						break;
					}
				}
				if (key) {
					shift.push_back(k);
					break;
				}
			}

		}
	}
	return shift;

}

int main() {
	int T,t=0;
	cin >> T;
	while (1) {
		vector<char>ascii(200, 0);//�ƽ�Ű�ڵ� ���� üũ�� �迭
		if (t == T) {
			break;//�׽�Ʈ ���̽� ����
		}
		t++;

		string a,A, W, S;
		cin >> A >> W >> S;

		//�ƽ�Ű�ڵ忡 ���� �ű��
		for (int i = 1;i <= A.size();i++) {
			ascii[A[i - 1]] = i;
		}
		//���� ����Ȯ��
		for (int i = 0;i <= W.size();i++) {
			W[i] = ascii[W[i]];
		}
		//��ȣ ���� Ȯ��
		for (int i = 0;i <= S.size();i++) {
			S[i] = ascii[S[i]];
		}
		
		if (S == W) {
			//��ȣ�� �����̶� ���� ��� 
			cout << "unique: 0" << endl;
		}
		else {
			vector<int> shift = RabinKarp(S, W, A);
			if (shift.empty()) {
				//������� ���
				cout << "no solution"<<endl;
			}
			else {
				if (shift.size() == 1) {
					cout << "unique: " << shift[0]<<endl;
				}
				else {
					cout << "ambiguous: ";
					for (int i = 0;i < shift.size();i++) {
						cout << shift[i] << " ";
					}
					cout << endl;
				}
			}

		}
	}
	return 0;
}