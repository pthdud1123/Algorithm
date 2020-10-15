#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#define endl '\n'

using namespace std;

int main() {
	int N;
	cin >> N;
	vector <int> arr;
	map <char, int>m;
	vector<string> a;
	for (int i = 0;i < N;i++) {
		string temp;
		cin >> temp;
		a.push_back(temp);
		reverse(a[i].begin(), a[i].end());
		
	}
	for (int i = 0;i < a.size();i++) {
		for (int j = 0;j < a[i].size();j++) {
			if (m.find(a[i][j]) == m.end()) {
				m[a[i][j]] = pow(10, j);
			}
			else {
				m[a[i][j]] += pow(10, j);
			}
		}
	}
	map <char, int>::iterator iter;
	for (iter = m.begin();iter != m.end();iter++) {
		arr.push_back(iter->second);
	}
	sort(arr.begin(), arr.end());
	int result = 0;
	int v = 9;
	for (int i = arr.size()-1;i >=0 ;i--) {
		result += arr[i] * v;
		v--;
	}
	cout << result << endl;
}