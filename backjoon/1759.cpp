#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define endl '\n'
using namespace std;
int L, C;
char arr[16];
int vowel = 0;
int consonant = 0;
int cnt;
vector<char>s;
vector<vector<char>>v;
void DFS(int col,int cnt) {
	if (col > C)return;
	if (cnt == L) {
		if (vowel >= 1 && consonant >= 2) {
			for (int i = 0;i < L;i++) {
				cout << s[i];
			}
			cout << endl;
		}
		return;
	}

	s.push_back(arr[col]);
	if (arr[col] == 'a' || arr[col] == 'i' || arr[col] == 'e' || arr[col] == 'o' || arr[col] == 'u')
		vowel++;
	else
		consonant++;
	DFS(col + 1, cnt + 1);
	s.pop_back();
	if (arr[col] == 'a' || arr[col] == 'i' || arr[col] == 'e' || arr[col] == 'o' || arr[col] == 'u')
		vowel--;
	else
		consonant--;
	DFS(col + 1, cnt);

	
}
int main() {
	cin >> L >> C;
	for (int i = 0;i < C;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);
	DFS(0,0);
	
}