#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<string>> ant;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		vector<string> antinfo;
		for (int j = 0;j < num;j++) {
			string food;
			cin >> food;
			antinfo.push_back(food);
		}
		ant.push_back(antinfo);
	}

	//먹이 이름 비교 하기
	for (int i = 0;i < N - 1;i++) {
		int index = 0;
		string root1 = ant[i][index];
		for (int j = i + 1;j < N;j++) {//225
			string spare = ant[j][index];
			bool check = true;
			int size = 0;
			if (ant[i] <= ant[j]) {
				size = ant[i].size();
			}
			else {
				size = ant[j].size();
			}
			for (int x = 0;x < size,check==true;x++) {
				if (x != 0) {
					root1 = ant[i][++index];
					spare = ant[j][index];
				}
				for (int k = 0;k < root1.size();k++) {//문자열의 최대 길이15 ->3,375->50,625
					if (root1[k] > spare[k]) {
						//root1는 spare보다 값이 작아야함./같은 경우 다음 인자를 가지고 서로 비교를 해야 함
						vector<string> temp1 = ant[i];
						ant[i] = ant[j];
						ant[j] = temp1;
						check = false;
					}
				}
			}

		}
	}
	//먹이 출력
	for (int i = 0;i < N;i++){
		string root = ant[i][j];
		for (int j = 0;j < ant[i].size();j++) {
			

		}
	}
	
}