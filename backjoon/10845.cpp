#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int> Q;
	for (int i = 0;i < N;i++) {
		string a;
		int number;
		cin >> a;
		if (a == "push") {
			cin >> number;
			Q.push(number);//큐를 원소안에 넣어 야함
		}
		if (a == "pop") {
			if (Q.empty() == true) {
				cout << -1<<endl;
			}
			else if (Q.empty() == false) {
				cout << Q.front()<<endl;
				Q.pop();
			}
		}
		if (a == "size") {
			cout << Q.size() << endl;
		}
		if (a == "empty") {
			if (Q.empty() == true) {
				cout << 1<<endl;
			}
			else if (Q.empty() == false) {
				cout << 0<<endl;
			}
		}
		if (a == "front") {
			if (Q.empty() == true) {
				cout << -1<<endl;
			}
			else  {
				cout << Q.front()<<endl;
			}
		}
		if (a == "back") {
			if (Q.empty() == true) {
				cout << -1<<endl;
			}
			else if (Q.empty() == false) {
				cout << Q.back()<<endl;
			}
		}

	}
}