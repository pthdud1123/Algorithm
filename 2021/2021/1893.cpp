#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<map>
using namespace std;

vector<int> maketable(string t) {
	vector<int> table(t.size(), 0);
	int j = 0;
	for (int i = 1;i < t.size();i++) {
		while (j > 0 && t[i] != t[j])
			j = table[j - 1];
		if (t[i] == t[j]) {
			table[i]=++j;
		}
	}
	return table;
}

vector<int> KMP(string p, string t, string a, map<char, int> o) {
	vector<int> shift;
	vector<int> numbert;
	int shiftsize = a.size();
	
	for (int j = 0;j < t.size();j++) {
		numbert.push_back((o[t[j]]) % shiftsize);//원문 이동
	}
	for (int i = 0;i < shiftsize;i++) {
		if(i!=0) {
			for (int j = 0;j < t.size();j++) {
				numbert[j] = (numbert[j] + 1) % shiftsize;
				if (numbert[j] - 1 == -1) {
					t[j] = a[a.size()-1];
				}
				else {
					t[j] = a[numbert[j] - 1];
				}
			}
		}
		int index = 0;
		int cnt = 0;
		vector<int> table = maketable(t);
		for (int j = 0;j < p.size();j++) {
			while (index > 0 && p[j] != t[index])
				index = table[index - 1];
			if (p[j] == t[index]) {
				if (index == t.size() - 1) {
					cnt++;
					index = table[index];
				}
				else {
					index++;
				}
			}
		}
		if (cnt == 1) {
			shift.push_back(i);
		}
	}
	return shift;
}
void outprint(vector<int>shift) {
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
				cout << " " << shift[i];
			}
			cout << endl;
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string A, W, S;
		map<char, int> order;
		cin >> A >> W >> S;
		for (int i = 0;i < A.size();i++) {
			order[A[i]] = (i+1)%A.size();
		}
		vector<int> shift = KMP(S, W,A, order);
		outprint(shift);
	}
}