#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

ifstream inp("test.inp");
ofstream out("test.out");

vector<int>arr;
long con = 0;
long target;
long arr2[500000][2];
long pre = -1;

int stockPairs(vector<int> stocksProfit, long target) {
	sort(stocksProfit.begin(), stocksProfit.end());
	int sum = 0;
	for (int index = 0;stocksProfit[index] <= target / 2;index++) {
		sum = stocksProfit[index];
		for (int j = index + 1;j < stocksProfit.size();j++) {
			if (sum + stocksProfit[j] == target) {
				con++;
				break;
			}
		}
	}
	return con;
}

int main() {
	int N;
	inp >> N;
	for (int i = 0;i < N;i++) {
		int nom;
		inp >> nom;
		arr.push_back(nom);
	}
	inp >> target;
	stockPairs(arr, target);
	
	int value = 0;
	int pre = -1;
	for (int i = 0;i < con;i++) {
		if (arr2[i][0] < arr[0]) {
			continue;
		}
		if (pre == -1) {
			pre = arr2[i][0];
			value++;
		}
		else {
			if (pre != arr2[i][0]) {
				pre = arr2[i][0];
				value++;
			}
		}
	}

	out << value << endl;
}