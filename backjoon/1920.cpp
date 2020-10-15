#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int  N,M;
	cin >> N;
	int arr_n[100001];

	for (int i = 0;i < N;i++)
	{
		int temp;
		cin >> temp;
		arr_n[i]=temp;
		
	}
	sort(arr_n, arr_n + N);
	
	cin >> M;
	for (int i = 0;i < M;i++) {
		int temp;
		int result;
		cin >> temp;
		int left = 0, right = N - 1;

		while (1) {
			int mid = (left + right) / 2;
			if (arr_n[mid] == temp) {
				result = 1;
				break;
			}
			else if (left >= right) {
				result = 0;
				break;
			}
			else if (temp > arr_n[mid]) {
				left = mid + 1;
			}
			else if (temp < arr_n[mid]) {
				right = mid - 1;
			}
		}
		cout << result << endl;
	}

	

	
}