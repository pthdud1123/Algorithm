#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<math.h>
#include<cmath>
#include<vector>
#define endl '\n'
#define le9 1000000000

using namespace std;

vector<string>CMD;
long long int number = 0;//NUM에 저장되 어있는 숫자
vector<long long int>num;
stack<long long int>s;
long long int rotation = 0;
long long int result = 0;
void gostack(long long int i) {
	if (CMD[i] == "END") {
		if (s.size() == 1) {
			if (s.top() > le9) {
				cout << "ERROR" << endl;
					s.pop();
					return;
			}
			else {
				cout << s.top() << endl;
				s.pop();
				return;
			}
		}
	
		else {
			cout << "ERROR" << endl;
			while (!s.empty()) {
				s.pop();
				
			}
			return;
		}
	}
	if (CMD[i] == "NUM") {
		s.push(num[number]);
		number++;
		gostack(i + 1);
	}
	if (CMD[i] == "DUP") {
		s.push(s.top());
		gostack(i + 1);

	}
	if (CMD[i] == "POP") {
		s.pop();
		gostack(i + 1);

	}
	if (CMD[i] == "INV") {
		s.top() *= -1;
		gostack(i + 1);

	}
	if (CMD[i] == "ADD") {
		int temp;
		temp = s.top();
		s.pop();
		s.top() += temp;
		gostack(i + 1);

	}
	if (CMD[i] == "MUL") {
		int temp;
		temp = s.top();
		s.pop();
		s.top() *= temp;
		gostack(i + 1);

	}
	if (CMD[i] == "DIV") {
		int temp;
		temp = s.top();
		s.pop();
		if (!s.empty()) {
			if ((s.top() < 0 && temp > 0) || (s.top() > 0 && temp < 0)) {
				s.top() /= abs(temp);
				s.top() *= -1;

			}
			else {
				s.top() /= abs(temp);
			}
			gostack(i + 1);
		}
		else {
			if (s.top() > le9) {
				cout << "ERROR" << endl;
				while (!s.empty()) {
					s.pop();
					return;
				}
			}
		}
	

	}
	if (CMD[i] == "MOD") {
		long long int temp;
		temp = s.top();
		s.pop();
		if (!s.empty()) {
			if ((s.top() < 0 && temp > 0) || (s.top() > 0 && temp < 0)) {
				s.top() %= abs(temp);
				s.top() *= -1;
			}
			else {
				s.top() %= abs(temp);
			}
			gostack(i + 1);
		}
		else {
			if (s.top() > le9) {
				cout << "ERROR" << endl;
				while (!s.empty()) {
					s.pop();
					return;
				}
			}
		}

	}
	return;
}
int main() {
	string add;
	int N;//입력받을 개수
	string space="0";
	while (space!="QUIT") {
		while (add != "END") {
			cin >> add;
			if (add == "QUIT")
				break;
			if (add == "NUM") {
				int temp;
				cin >> temp;
				num.push_back(temp);
			}
			CMD.push_back(add);
			rotation++;
		}
		if (add == "QUIT")
			break;
		cin >> N;
		int value;
		for (int i = 0;i < N;i++) {
			cin >> value;
			s.push(value);
			gostack(0);
			number = 0;
		}
	
		num.clear();
		CMD.clear();
		rotation = 0;
		number = 0;
		add = "";

	}
	
}