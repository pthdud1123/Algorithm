#include<iostream>
#include<cmath>
using namespace std;

int num[25];
char buho[25];
int N,Max=(pow(2,31)-1)*-1;

int calculate(int a,int b,char c) 
{
	if (c == '+') {
		return a + b;
	}
	else if (c == '-') {
		return a - b;
	}
	else if (c == '*') {
		return a * b;
	}
	else {
		cout << "error";
		return 0;
	}

}


void bracket(int index,int sum) {//sum값은 무조건 0으로 시작!
	if (N -1 < index) {

		if (Max < sum) {
			Max = sum;
		}
		return;
	}
	//uses braket
	if (index != N - 1) {
		int temp = calculate(num[index + 1], num[index + 3], buho[index + 2]);
		bracket(index + 4, calculate(sum, temp, buho[index]));
	}
	//uses braket
	bracket(index + 2, calculate(sum, num[index + 1], buho[index]));
	
	


}
int main() {
	
	cin >> N;
	for (int i = 1;i <= N;i++) {
		if (i % 2 == 1) {
			cin >> num[i];
		}
		else {
			char temp;
			cin >> buho[i];
		}
	}
	buho[0] = '+';
	bracket(0, 0);
	cout << Max << endl;

}
//간단한 DFS문제 
//한점에서 부터시작하여 축적해서 오다가 조건에 맞춘 값 가져오기