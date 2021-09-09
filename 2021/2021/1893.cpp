#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

vector<int> RabinKarp(string S, string W,string A) {
	vector<int> shift;//반환할 쉬프트 값
	int Ssize = S.size(), Wsize = W.size();
	int whash=0,shash=0;
	//W해시값 구하기
	for (int i = 0,j=0;i < Wsize;i++) {
		whash = whash + A[W[Wsize - 1 - i]-1] * pow(2, j);
		j++;
	}
	//각 해시 값 구해서 W해시 값과 비교하기
	for (int k = 1;k < Wsize;k++) {//k는 이동한 쉬프트에서 원문값이 있는 지 체크
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
				//다음값 =2*(이전 해시 값 - 이전 문자열 맨 앞자리(a))-현재 추가 되는 뒷자리 문자(b).
				int a = A[S[i - 1]-1] * pow(2, Wsize - 1);
				int b = A[S[i + Wsize - 1]-1] * pow(2, 0);
				shash = 2 * (shash - a) + b;
			}
			if (shash == whash) {
				//해쉬값이 맞다면 문자 값도 맞는지 확인해주기
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
		vector<char>ascii(200, 0);//아스키코드 순서 체크할 배열
		if (t == T) {
			break;//테스트 케이스 종료
		}
		t++;

		string a,A, W, S;
		cin >> A >> W >> S;

		//아스키코드에 순서 매기기
		for (int i = 1;i <= A.size();i++) {
			ascii[A[i - 1]] = i;
		}
		//원문 순서확인
		for (int i = 0;i <= W.size();i++) {
			W[i] = ascii[W[i]];
		}
		//암호 순서 확인
		for (int i = 0;i <= S.size();i++) {
			S[i] = ascii[S[i]];
		}
		
		if (S == W) {
			//암호랑 원문이랑 같은 경우 
			cout << "unique: 0" << endl;
		}
		else {
			vector<int> shift = RabinKarp(S, W, A);
			if (shift.empty()) {
				//비어있을 경우
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