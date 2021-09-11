//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//vector<int> maketable(string t) {
//	vector<int> table(t.size(),0);
//	int j = 0;
//	for (int i = 0;i < t.size();i++) {
//		while (j > 0 && t[j] != t[i + j]) {
//			j = table[j - 1];
//		}
//		if(t[i]==t[j]) {
//			table.push_back(++j);
//		}
//	}
//	return table;
//}
//
//vector<int> KMP(int ascii[],string w,string s,string a){
//	vector<int> shift;
//	vector<int> t=maketable(w);
//	for (int k = 1;k < a.size();k++) {
//		int j = 0;
//		for (int i = 0;i < s.size()-w.size();i++) {
//			while (j > 0 && a[ascii[s[i]]] != a[(ascii[w[j]]+k)%a.size()]) {
//				j = t[j - 1];
//			}
//			if (a[ascii[s[i]]] == a[(ascii[w[j]] + k) % a.size()]) {
//				if (j == w.size() - 1) {
//					shift.push_back(k);
//					break;
//				}
//				else {
//					j++;
//				}
//			}
//		}
//	}
//	return shift;
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		string A, W, S;
//		cin >> A >> W >> S;
//		if (W == S) {
//			cout << "unique: 0" << endl;
//			continue;
//		}
//		int ascii[300] = {0};
//		for (int i = 0;i < A.size();i++) {
//			ascii[A[i]] = i;
//		}
//		vector<int> shift=KMP(ascii, W, S,A);
//		if (shift.empty()) {
//			cout << "no solution" << endl;
//		}
//		else {
//			if (shift.size() == 1) {
//				cout << "unique: " << shift[0] << endl;
//			}
//			else {
//				cout << "ambiguous: ";
//				for (int i = 0;i < shift.size();i++) {
//					cout << shift[i] << " ";
//				}
//				cout << endl;
//			}
//		}
//	}
//}
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

vector<int> table(string W) {
	vector<int> t(W.size() + 1, 0);
	int j = 0;
	for (int i = 1;i < W.size();i++) {
		while (j > 0 && W[i] != W[j]) {
			j = t[i - 1];
		}
		if (W[i] == W[j]) {
			t[i] = ++j;
		}
	}
	return t;
}
bool KMP(string p, string t) {
	vector<int> checktable = table(t);
	int j = 0;
	for (int i = 0;i < p.size() - t.size();i++) {
		while (j > 0 && p[i] != t[j]) {
			j = checktable[j - 1];
		}
		if (p[i] == t[j]) {
			if (j == t.size() - 1) {
				return true;
			}
			else {
				j++;
			}
		}
	}
	return false;

}

vector<int> RabinKarp(string S, string W, string A) {
	vector<int> shift;//반환할 쉬프트 값
	int Ssize = S.size(), Wsize = W.size();

	//각 해시 값 구해서 W해시 값과 비교하기
	for (int k = 1;k < Wsize;k++) {//k는 이동한 쉬프트에서 원문값이 있는 지 체크

		for (int i = 0;i < Ssize;i++) {
			S[i]++;
			if (S[i] > Wsize)
				S[i] = 1;
		}

		bool key = KMP(S, W);
		if (key) {
			shift.push_back(k);
		}

	}
	return shift;

}

int main() {
	int T, t = 0;
	cin >> T;
	while (1) {
		vector<char>ascii(200, 0);//아스키코드 순서 체크할 배열
		if (t == T) {
			break;//테스트 케이스 종료
		}
		t++;

		string A, W, S;
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
				cout << "no solution" << endl;
			}
			else {
				if (shift.size() == 1) {
					cout << "unique: " << shift[0] << endl;
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