#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int N, M, D;
int main() {
	cin >> N >> M >> D;
	int arr[16][16];
	vector<pair<int, int>> enemy;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				enemy.push_back({ i,j });
			}
		}
	}

	vector<int>archer;

	for (int i = 0;i < M - 3;i++) {
		archer.push_back(0);
	}

	for (int i = 0;i < 3;i++) {
		archer.push_back(1);
	}

	int result = 0;
	do {
		
		vector<pair<int, int>>temp = enemy;
		vector<int>v = archer;
		
		int cnt = 0;

		while (!temp.empty()) {
 			int y = N;
			
			vector<int>target;
			for (int i = 0;i < v.size();i++) {
				if (v[i] == 1) {
					int x = i;
					int targetdist = abs(N - temp[0].first) + abs(x - temp[0].second);
					int idx = 0;
					int enemyX = temp[0].second;
					for (int j = 1;j < temp.size();j++) {
						int dist = abs(N - temp[j].first) + abs(x - temp[j].second);
						if (targetdist > dist) {
							idx = j;
							enemyX = temp[j].second;
							targetdist = dist;
						}
						if (targetdist == dist && temp[j].second < enemyX) {
							idx = j;
							enemyX = temp[j].second;
						}
						
					}
					if (targetdist <= D) {
						target.push_back(idx);
					}
					

				}

			}
			sort(target.begin(), target.end());
			target.erase(unique(target.begin(), target.end()), target.end());
			
			int shoot = 0;//인덱스가 지워지면서 한개씩 앞으로 당겨지니까.
			for (int k = 0;k < target.size();k++) {
				temp.erase(temp.begin() + (target[k]-shoot++));
				cnt++;
			}
			if (temp.empty()) {
				break;
			}
			vector<pair<int, int>>copyarr;
			for (int i = 0;i < temp.size();i++) {
				if (temp[i].first < N - 1) {
					copyarr.push_back({ temp[i].first + 1, temp[i].second });
				}
			}
			temp = copyarr;


		}
		result = max(result, cnt);
	} while (next_permutation(archer.begin(), archer.end()));
	
	cout << result << endl;
	return 0;
}