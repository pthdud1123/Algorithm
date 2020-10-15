#include<iostream>
#include<algorithm>
#include<math.h>
#pragma warning(disable:4996)
using namespace std;

int arr[400000] = {0,};
int main() {
	int n;//n:의견의 개수
	/*숫자의 반올림->round()
	  올림 하려면->ceil()
	  잘라서 버릴려면->floor()*/
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);//정렬을 해준다.
	//절사평균
	int count = round(n * 0.15);
	int sum = 0, average = 0;
	for (int i = count;i < n - count;i++) {
		sum += arr[i];
	}
	float all_count = n - (2 * count);
	average = round(sum / all_count);
	if (n == 0) {
		average = 0;
	}
	cout << average;
	return 0;

}