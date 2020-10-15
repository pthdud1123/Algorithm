#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct Prefer {
	vector <int>candidate;//선호가는 후보자를 순서대로 입력받게 하기위해서
};
int main() {
	int T;//테스트 케이스의 수
	int C, V;//후보자의 수C, 유권자의 수V
	vector<Prefer>president;//선호도 표를 저장하기 위한 벡터
	cin >> T;
	for (int i = 0;i < T;i++) {
		int C, V;//후보자의 수C, 유권자의 수V
		vector<Prefer>president;//선호도 표를 저장하기 위한 벡터

		cin >> C >> V;
		for (int j = 0;j < V;j++) {
			Prefer temp;
			for (int k = 0;k < C;k++) {
				int n;
				cin >> n;
				temp.candidate.push_back(n);
			}
			president.push_back(temp);
		}//선호도 입력받기 성공
		int *arr = (int *)malloc(sizeof(int)*(C + 1));
		for (int j = 0;j <= C;j++) {
			arr[j] = 0;//0으로 초기화 해주어야 한다.
		}
		for (int j = 0;j < V;j++) {
			arr[president[j].candidate[0]] += 1;//선호도 순 알아보기
		}
		int big1 = arr[0], big1number = 0;
		for (int j = 1;j <= C;j++) {
			if (big1 < arr[j]) {
				big1 = arr[j];
				big1number = j;
			}
		}
		int big2, big2number=-1;
		for (int j = 1;j <= C;j++) {
			if (j != big1number && big2number == -1) {
				big2 = arr[j];
				big2number = j;
			}
			else if (j != big1number && big2 < arr[j]) {
				big2 = arr[j];
				big2number = j;
			}
		}
		int majority = ceil((float)V / 2.0);
		if (majority <= arr[big1number]) {
			//과반수 이상으로 표를 받은경우
			cout << big1number << " " << 1 << endl;
		}
		else {
			int B1 = 0, B2 = 0;
			for (int j = 0;j < V;j++) {
				for (int k = 0;k < C;k++) {
					if (president[j].candidate[k] == big1number) {
						B1++;
						break;
					}
					else if (president[j].candidate[k] == big2number) {
						B2++;
						break;
					}
				}
			}


			if (B1 < B2) {
				cout << big2number << " " << 2 << endl;
			}
			else {
				cout << big1number << " " << 2 << endl;
			}
		}
	
	}
}