#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#pragma warning(disable:4996)
#define N 6

using namespace std;
struct othello {
	vector<char>value;
};
void one_B(vector<othello>&a, int line, int row) {
	int L = line - 1;
	int R = row - 1;
	if (L < 0)return;
	if (R < 0)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'W') {
		one_B(a, L, R);
		return;
	}
	if (a[L].value[R] == 'B') {
		L++;R++;
		if (L > N-1 || R >  N - 1)return;
		while (a[L].value[R] == 'W') {
			a[L].value[R] = 'B';
			L++;R++;
			if (L >  N - 1 || R > N - 1)return;

		}
	}
	return;
}
void one_W(vector<othello>&a, int line, int row) {
	int L = line - 1;
	int R = row - 1;
	if (L < 0)return;
	if (R < 0)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'B') {
		one_W(a, L, R);
		return;
	}
	if (a[L].value[R] == 'W') {
		L++;R++;
		if (L > N - 1 || R >  N - 1)return;
		while (a[L].value[R] == 'B') {
			a[L].value[R] = 'W';
			L++;R++;
			if (L >  N - 1 || R >  N - 1)return;

		}
	}
	return;
}
void two_B(vector<othello>&a, int line, int row) {
	int L = line - 1;
	int R = row;
	if (L < 0)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'W') {
		two_B(a, L, R);
		return;
	}
	if (a[L].value[R] == 'B') {
		L++;
		if (L >  N - 1)return;
		while (a[L].value[R] == 'W') {
			a[L].value[R] = 'B';
			L++;
			if (L >  N - 1)return;

		}
	}
	return;
}
void two_W(vector<othello>&a, int line, int row) {
	int L = line - 1;
	int R = row;
	if (L < 0)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'B') {
		two_W(a, L, R);
		return;
	}
	if (a[L].value[R] == 'W') {
		L++;
		if (L >  N - 1)return;
		while (a[L].value[R] == 'B') {
			a[L].value[R] = 'W';
			L++;
			if (L >  N - 1)return;
		}
	}
	return;
}
void three_B(vector<othello>&a, int line, int row) {
	int L = line - 1;
	int R = row + 1;
	if (L < 0)return;
	if (R >  N - 1)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'W') {
		three_B(a, L, R);
		return;
	}
	if (a[L].value[R] == 'B') {
		L++;R--;
		if (L >  N - 1 || R < 0)return;
		while (a[L].value[R] == 'W') {
			a[L].value[R] = 'B';
			L++;R--;
			if (L >  N - 1 || R < 0)return;

		}
	}
	return;
}
void three_W(vector<othello>&a, int line, int row) {
	int L = line - 1;
	int R = row + 1;
	if (L < 0)return;
	if (R >  N - 1)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'B') {
		three_W(a, L, R);
		return;
	}
	if (a[L].value[R] == 'W') {
		L++;R--;
		if (L >  N - 1 || R < 0)return;

		while (a[L].value[R] == 'B') {
			a[L].value[R] = 'W';
			L++;R--;
			if (L >  N - 1 || R < 0)return;

		}
	}
	return;
}
void four_B(vector<othello>&a, int line, int row) {
	int L = line;
	int R = row + 1;
	if (R > N - 1)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'W') {
		four_B(a, L, R);
		return;
	}
	if (a[L].value[R] == 'B') {
		R--;
		if (R < 0)return;
		while (a[L].value[R] == 'W') {
			a[L].value[R] = 'B';
			R--;
			if (R < 0)return;

		}
	}
	return;
}
void four_W(vector<othello>&a, int line, int row) {
	int L = line;
	int R = row + 1;
	if (R > N - 1)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'B') {
		four_W(a, L, R);
		return;
	}
	if (a[L].value[R] == 'W') {
		R--;
		if (R < 0)return;

		while (a[L].value[R] == 'B') {
			a[L].value[R] = 'W';
			R--;
			if (R < 0)return;

		}
	}
	return;
}
void five_B(vector<othello>&a, int line, int row) {
	int L = line + 1;
	int R = row + 1;
	if (L > N - 1)return;
	if (R >  N - 1)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'W') {
		five_B(a, L, R);
		return;
	}
	if (a[L].value[R] == 'B') {
		L--;R--;
		if (R < 0||L<0)return;

		while (a[L].value[R] == 'W') {
			a[L].value[R] = 'B';
			L--;R--;
			if (R < 0 || L<0)return;

		}
	}
	return;
}
void five_W(vector<othello>&a, int line, int row) {
	int L = line + 1;
	int R = row + 1;
	if (L >  N - 1)return;
	if (R >  N - 1)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'B') {
		five_W(a, L, R);
		return;
	}
	if (a[L].value[R] == 'W') {
		L--;R--;
		if (R < 0 || L<0)return;

		while (a[L].value[R] == 'B') {
			a[L].value[R] = 'W';
			L--;R--;
			if (R < 0 || L<0)return;

		}
	}
	return;
}
void six_B(vector<othello>&a, int line, int row) {
	int L = line + 1;
	int R = row ;
	if (L > N - 1)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'W') {
		six_B(a, L, R);
		return;
	}
	if (a[L].value[R] == 'B') {
		L--;
		if (L<0)return;

		while (a[L].value[R] == 'W') {
			a[L].value[R] = 'B';
			L--;
			if (L<0)return;

		}
	}
	return;
}
void six_W(vector<othello>&a, int line, int row) {
	int L = line + 1;
	int R = row;
	if (L >  N - 1)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'B') {
		six_W(a, L, R);
		return;
	}
	if (a[L].value[R] == 'W') {
		L--;
		if (L<0)return;

		while (a[L].value[R] == 'B') {
			a[L].value[R] = 'W';
			L--;
			if (L<0)return;

		}
	}
	return;
}
void seven_B(vector<othello>&a, int line, int row) {
	int L = line + 1;
	int R = row - 1;
	if (L > N - 1)return;
	if (R < 0)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'W') {
		seven_B(a, L, R);
		return;
	}
	if (a[L].value[R] == 'B') {
		L--;R++;
		if (L<0||R> N - 1)return;

		while (a[L].value[R] == 'W') {
			a[L].value[R] = 'B';
			L--;R++;
			if (L<0 || R> N - 1)return;

		}
	}
	return;
}
void seven_W(vector<othello>&a, int line, int row) {
	int L = line + 1;
	int R = row - 1;
	if (L >  N - 1)return;
	if (R < 0)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'B') {
		seven_W(a, L, R);
		return;
	}
	if (a[L].value[R] == 'W') {
		L--;R++;
		if (L<0 || R> N - 1)return;

		while (a[L].value[R] == 'B') {
			a[L].value[R] = 'W';
			L--;R++;
			if (L<0 || R> N - 1)return;

		}
	}
	return;
}
void eight_B(vector<othello>&a, int line, int row) {
	int L = line ;
	int R = row - 1;
	if (R < 0)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'W') {
		eight_B(a, L, R);
		return;
	}
	if (a[L].value[R] == 'B') {
		R++;
		if (R >  N - 1)return;
		while (a[L].value[R] == 'W') {
			a[L].value[R] = 'B';
			R++;
			if (R >  N - 1)return;

		}
	}
	return;
}
void eight_W(vector<othello>&a, int line, int row) {
	int L = line;
	int R = row - 1;
	if (R < 0)return;
	if (a[L].value[R] == '.')
		return;
	if (a[L].value[R] == 'B') {
		eight_W(a, L, R);
		return;
	}
	if (a[L].value[R] == 'W') {
		R++;
		if (R >  N - 1)return;

		while (a[L].value[R] == 'B') {
			a[L].value[R] = 'W';
			R++;
			if (R >  N - 1)return;

		}
	}
	return;
}

int main() {
	int n;//첫줄에 게인 로그의 N이 주어짐
	cin >> n;
	int line, row;//행과 열
	vector<othello>arr;
	//.으로 N*N초기화
	for (int i = 0;i < N;i++) {
		othello temp;
		for (int j = 0;j < N;j++) {
			char a = '.';
			temp.value.push_back(a);
		}
		arr.push_back(temp);
	}
	//초기 게임판 형태 만들어주기
	arr[2].value[2] = 'W';//3행 3열
	arr[3].value[3] = 'W';//4행4열
	arr[2].value[3] = 'B';//3행 4열
	arr[3].value[2] = 'B';//4행 3열

	for (int i = 0;i < n;i++) {
		cin >> line >> row;//행과 열위치를 알아낸다.
		if (i % 2 == 0) {
			//검정색 돌을 놓는다.
			arr[line - 1].value[row - 1] = 'B';
			one_B(arr, line - 1, row - 1);
			two_B(arr, line - 1, row - 1);
			three_B(arr, line - 1, row - 1);
			four_B(arr, line - 1, row - 1);
			five_B(arr, line - 1, row - 1);
			six_B(arr, line - 1, row - 1);
			seven_B(arr, line - 1, row - 1);
			eight_B(arr, line - 1, row - 1);
		}
		else if (i % 2 == 1) {
			//흰색 돌을 놓는다.
			arr[line - 1].value[row - 1] = 'W';
			one_W(arr, line - 1, row - 1);
			two_W(arr, line - 1, row - 1);
			three_W(arr, line - 1, row - 1);
			four_W(arr, line - 1, row - 1);
			five_W(arr, line - 1, row - 1);
			six_W(arr, line - 1, row - 1);
			seven_W(arr, line - 1, row - 1);
			eight_W(arr, line - 1, row - 1);
		}
	}

	int countB = 0,countW = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << arr[i].value[j];
			if (arr[i].value[j] == 'B')countB++;
			if (arr[i].value[j] == 'W')countW++;
		}
		cout << endl;
	}
	if (countB < countW) {
		cout << "White" << endl;
	}
	if (countB > countW) {
		cout << "Black" << endl;
	}
	return 0;
}