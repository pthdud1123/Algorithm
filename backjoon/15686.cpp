#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#define endl '\n'
using namespace std;
struct point {
	int x;
	int y;
	bool check = false;
};
int cnt = 0;
int N, M;
int Min = 987654321;
int street = 0;
vector<point>home;
vector<point>chicken;
vector<point>selectchicken;

void DFS(int row,int cnt) {
	
	if (cnt==M) {
		int r = 0;
		for (int i = 0;i < home.size();i++) {
			int v = 987654321;
			for (int j = 0;j < selectchicken.size();j++) {
				v = min(v, abs(home[i].x - selectchicken[j].x) + abs(home[i].y - selectchicken[j].y));
			}
			r += v;
		}
		if (Min > r)Min = r;
		return;
	}
	for (int i = 0;i <chicken.size();i++) {
		selectchicken.push_back(chicken[i]);
		DFS(row + 1, cnt + 1);
		selectchicken.pop_back();
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int Temp;
			cin >> Temp;
			point temp;
			if (Temp == 1) {//home
				temp.x = i + 1;
				temp.y = j + 1;
				home.push_back(temp);
			}
			else if (Temp == 2) {//ġŲ
				temp.x = i + 1;
				temp.y = j + 1;
				chicken.push_back(temp);
			}
		}
	}
	
	DFS(0, 0);
	cout << Min << endl;
}