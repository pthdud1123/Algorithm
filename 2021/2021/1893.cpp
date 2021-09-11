#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> maketable(string t) {
	vector<int> table(t.size(),0);
	int j = 0;
	for (int i = 0;i < t.size();i++) {
		while (j > 0 && t[j] != t[i + j]) {
			j = table[j - 1];
		}
		if(t[i]==t[j]) {
			table.push_back(++j);
		}
	}
	return table;
}

vector<int> KMP(int ascii[],string w,string s,string a){
	vector<int> shift;
	vector<int> t=maketable(w);
	for (int k = 0;k < a.size();k++) {
		int j = 0;
		int check = 0;
		for (int i = 0;i < s.size();i++) {
			while (j > 0 && s[i] != a[(ascii[w[j]]+k)%a.size()]) {
				j = t[j - 1];
			}
			if (s[i] == a[(ascii[w[j]] + k) % a.size()]) {
				if (j == w.size() - 1) {
					check++;
					j = t[j];
				}
				else {
					j++;
				}
			}
		}
		if (check == 1) {
			shift.push_back(k);
		}
	}
	return shift;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string A, W, S;
		cin >> A >> W >> S;
		int ascii[300] = {0};
		for (int i = 0;i < A.size();i++) {
			ascii[A[i]] = i;
		}
		vector<int> shift=KMP(ascii, W, S,A);
		if (shift.empty()) {
			cout << "no solution" << endl;
		}
		else {
			if (shift.size() == 1) {
				cout << "unique: " << shift[0] << endl;
			}
			else {
				cout << "ambiguous:";
				for (int i = 0;i < shift.size();i++) {
					cout << ' ' << shift[i];
				}
				cout << endl;
			}
		}
	}
}