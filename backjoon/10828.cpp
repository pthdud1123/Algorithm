#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int N;//����� ��
	cin >> N;
	stack<int> s;//int�� �ڷ����� �����ϴ� ���� ����
	string a;

	for (int i = 0;i < N;i++) {

		cin >> a;


		if (a == "push") {
			int number;
			cin >> number;
			s.push(number);
		}
		else if (a == "pop") {

			if (s.empty() == 1)//������ ��������� 1
			{
				cout << -1<<endl;
			}
			else if (s.empty() == 0) {//������ ������� ������ 0
				cout << s.top()<<endl;
				s.pop();
			}
		}
		else if (a == "top") {
			if (s.empty() == 1) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
			}
		}
		else if (a == "size") {
			cout << s.size()<<endl;
		}
		else if (a == "empty") {
			cout << s.empty()<<endl;
		}

	}
}