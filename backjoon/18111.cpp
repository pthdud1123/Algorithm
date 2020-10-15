#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	//블록을 제거하여 인벤토리에 넣는다->2초
	//인벤토리에서 블록을 꺼내어(i,j)위에 놓는다.->1초
	//땅고르기 작업에 걸리는 최소시간과 그 경우 땅의 높이를 출력하시오
	//땅의 높이는 256을 초과할 수가 없다. 음수가 될 수없다.

	long long N, M, B;//N:세로,M:가로,B:인벤토리안에 들어가있는 블록의 수
	long long time = 0, high, Max = -1, min = 266, Max_num = 0,min_num=0, Max_x = -1, Max_y = -1, min_x = -1, min_y = -1;//time시간,high높이,x축위치,y축 위치,
	cin >> N >> M >> B;
	//int land[501][501];//아차원 배열은 필요 없을 거 같다.

	int land[257] = {0,};//땅의 높이
	int a;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> a;
			land[a] += 1;//땅의 수를 입력함7
		}
	}
	//똑같은 높이 들의 땅의 수가 적은 것들이 인벤토리에 있는 것으로 채워질 경우
	//그러지 못해서 땅을 파야 하는 경우
	//최고의 높이와 제일 작은 높이 를 뺀다..
	//1이날 경우 인벤토리에서 채워질수있는지 확인 한다.->안된다면 높은것을 다시빼고 다시 높은 것과 낮은것의 차를 구한다.
	//2이상 날 경우 높은거의 인벤토리를 뺀다(인벤토리+1해주는 것도 생각)
	//최소한 시간을 적게 하고 싶음
	for (int i = 0;i < 257;i++) {
		if (land[i] > Max) {
			Max = land[i];
			Max_num = i;
		}
		if (land[i] < min&&land[i]!=0) {
			min = land[i];
			min_num = i;
		}
	}

	//땅의 개수의 Max값과Min값이 같아질때 까지 돌린다.
	while (Max != N*M) {
		//땅의 수가 적은 것를 많은 것에 맞추도록 한다.
		//근데 이러면 시간이 증가하면 어떻게 ?
		//1.땅의 수가 적은 것을 많은 것에 맞추도록한다.
		//2.땅의 수가 많은 것을 적은 것에 맞추도록 한다.
		//3.땅을 채울수 있는거 부터 B 조건에 충족하면 파고 조건에 충족하지 못한다.면 판다.
		if (B >= min) {
			
			if (Max_num < min_num) {
				B += min;//땅을 파고 인벤토리에 넣는다.
				time += min * 2;//그 높이 들의 땅을 다 판다.
				land[min_num] = 0;
				min_num--;
				land[min_num] += min;
			}
			else if (Max_num > min_num) {
				
				B -= min;//땅을 채운다.
				time += min;//각땅마다 하나씩 채웠으니까 시간을 증가 한다.
				land[min_num] = 0;
				min_num++;
				land[min_num] += min;
			}
			else if (Max == min) {
				if (Max_num < min_num) {
					time += Max;
					B -= Max;
					land[Max_num] = 0;
					Max_num++;
					land[Max_num] = Max;

				}
				else if (Max_num > min_num) {
					time += min;
					B -= min;
					land[min_num] = 0;
					min_num++;
					land[min_num] = min;

				}
			}
		}
		else if (B<min) {
			//땅을 채워넣을 수가 없을때
		
			if (Max_num > min_num) {
				B += Max;//땅을 파고 인벤토리에 넣는다.
				time += Max * 2;//그 높이 들의 땅을 다 판다.
				land[Max_num] = 0;
				Max_num--;
				land[Max_num] += Max;
			}
			
		
			

		}

		for (int i = 0;i <  257;i++) {
			if (land[i] > Max) {
				Max = land[i];
				Max_num = i;
			}
			if (land[i] < min&&land[i] != -1) {
				min = land[i];
				min_num = i;
			}
		}
		
	}
	cout << time <<" "<< Max_num;

}
