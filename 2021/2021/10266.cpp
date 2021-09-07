#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 360000
//참고사이트 : https://chanhuiseok.github.io/posts/algo-14/


int n;
vector<int> watch(MAX * 2-1, 0);
vector<int> check_table(MAX,-1);


void make_table(vector<int> watch2,vector<int> &check_table,int size) {
	int front = 0, matched = 0;
	check_table[1]=0;//문자열 길이가 1이면 경계가 없음.
	for (int i = 2;i <= size;i++) {
		int end = i - 1;
		if (watch2[front] == watch2[end]) {
			matched++;
			check_table[i]=matched;
			front = matched;
		}
		else {
			matched = 0;
			check_table[i]=matched;
			front = matched;
		}
	}

}


int main() {

	cin >> n;
	vector<int> target_watch(n, 0);
	bool key = false;
	
	for (int i = 0;i < n;i++) {
		int index;
		cin >> index;
		watch[index] = watch[MAX + index] = 1;
	}

	//target_watch
	for (int i = 0;i < n;i++) {
		int value;
		cin >> value;
		target_watch[i] = value;
	}
	sort(target_watch.begin(), target_watch.end());

	int size = target_watch[n - 1] - target_watch[0] + 1;
	vector<int> watch2(size,0);

	int s = target_watch[0];
	for (int i = 0;i < n;i++) {
		watch2[target_watch[i] - s] = 1;
	}

	
	//watch[2]접두사 접미사 테이블 만들기
	make_table(watch2,check_table,size);

	//KMP알고리즘

	for (int i = 0;i <= MAX * 2 - n ;i++) {
		int matched = 0;
		for (int j = 0;j < size;j++) {
			if (watch[i + j] == watch2[j]) {
				matched++;
			}
			else {
				//같지 않을 때
				i = i + ((j + 1) - check_table[j + 1]) - 1;
				break;
			}
		}
		if (matched == size) {
			key = true;
			break;
		}

	}
	


	if (key) {
		cout << "possible";
	}
	else {
		cout << "impossible";
	}

}
