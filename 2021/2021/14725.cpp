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

	//���� �̸� �� �ϱ�
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
				for (int k = 0;k < root1.size();k++) {//���ڿ��� �ִ� ����15 ->3,375->50,625
					if (root1[k] > spare[k]) {
						//root1�� spare���� ���� �۾ƾ���./���� ��� ���� ���ڸ� ������ ���� �񱳸� �ؾ� ��
						vector<string> temp1 = ant[i];
						ant[i] = ant[j];
						ant[j] = temp1;
						check = false;
					}
				}
			}

		}
	}
	//���� ���
	for (int i = 0;i < N;i++){
		string root = ant[i][j];
		for (int j = 0;j < ant[i].size();j++) {
			

		}
	}
	
}