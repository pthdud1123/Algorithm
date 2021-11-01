#include<iostream>
#include<string.h>
#include<vector>
#define MAX 360000
using namespace std;

vector<int>make_table(string w) {
	int size = w.size();
	vector<int>table(size, 0);
	int j = 0;
	for (int i = 1;i < size;i++) {
		while (j > 0 && w[i] != w[j])
			j = table[j - 1];
		if (w[i] == w[j]) {
			table[i] = ++j;
		}
	}
	return table;
}
//¸Þ·î
bool KMP(string original, string target) {
	vector<int>checktable = make_table(target);
	int j = 0;
	for(int i=0;i< original.size();i++){
		while (j > 0 && original[i] != target[j]) {
			j = checktable[j - 1];
		}
		if (original[i] == target[j]) {
			if (j == target.size() - 1) {
				return true;
			}
			else {
				j++;
			}
		}
	}
	return false;
}

int main() {
	int n;
	string w1, w2;
	for (int i = 0;i < MAX;i++) {
		w1 += '0';
		w2 += '0';
	}
	cin >> n;
	for (int i = 0;i < n;i++) {
		int temp;
		cin >> temp;
		w1[temp] = 1;
	}
	for (int i = 0;i < n;i++) {
		int temp;
		cin >> temp;
		w2[temp] = 1;
	}
	string parent = w1 + w1;
	if (KMP(parent, w2))
		cout << "possible";
	else
		cout << "impossible";
}