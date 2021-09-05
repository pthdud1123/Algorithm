#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	vector<vector<int>> watch;
	vector<vector<int>> angle;
	int n;
	cin >> n;
	for (int q = 0;q < 2;q++) {
		vector<int> tempwatch;
		for (int i = 0;i < n;i++) {
			int temp;
			cin >> temp;
			tempwatch.push_back(temp);
		}
		sort(tempwatch.begin(), tempwatch.end());
		watch.push_back(tempwatch);
	}
	//각 근접해있는 시계바늘 사이간의 angle구하기
	for (int i = 0;i < 2;i++) {
		vector<int> tempangle;
		for (int j = 0;j < n-1;j++) {
			int a;
			a = watch[i][j + 1] - watch[i][j];
			if (a >= 180000) {
				a = 360000 - a;
			}
			tempangle.push_back(a);
		}
		angle.push_back(tempangle);
	}

	if (angle[0]==angle[1]) {
		cout << "possible";
	}
	else {
		cout << "impossible";
	}

}