#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
	list<char>L;
	string a;
	cin >> a;
	for (int i = 0;i < a.length();i++) {
		L.push_back(a[i]);
	}
	int M;
	cin >> M;
	list<char>::iterator iter = L.end();//����Ʈ �ݺ��� ���� ����
	for (int i = 0;i < M;i++) {
		
		char O;
		cin >> O;
		if (O == 'L') {
			if(L.begin()!=iter)
			iter--;
		}
		if (O == 'D') {
			if (L.end() != iter) {
				iter++;
			}
		}
		if (O == 'B') {
			if (L.begin() != iter) {
				list<char>::iterator v = iter;
				v--;
				L.erase(v);
				//������ �Ǹ� ���ͷ�������ġ�� �ٲ�°Ŵ� �ƴ���,,,��,,,����,,,
				
			}

		}
		if (O == 'P') {
			
			char memo;
			cin >> memo;
			L.insert(iter, memo);
		}
	}
	iter = L.begin();
	while (1) {
		cout << *iter;
		iter++;
		if (iter == L.end()) {
			cout << endl;
			break;
		}
	}
}