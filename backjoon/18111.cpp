#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	//����� �����Ͽ� �κ��丮�� �ִ´�->2��
	//�κ��丮���� ����� ������(i,j)���� ���´�.->1��
	//������ �۾��� �ɸ��� �ּҽð��� �� ��� ���� ���̸� ����Ͻÿ�
	//���� ���̴� 256�� �ʰ��� ���� ����. ������ �� ������.

	long long N, M, B;//N:����,M:����,B:�κ��丮�ȿ� ���ִ� ����� ��
	long long time = 0, high, Max = -1, min = 266, Max_num = 0,min_num=0, Max_x = -1, Max_y = -1, min_x = -1, min_y = -1;//time�ð�,high����,x����ġ,y�� ��ġ,
	cin >> N >> M >> B;
	//int land[501][501];//������ �迭�� �ʿ� ���� �� ����.

	int land[257] = {0,};//���� ����
	int a;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> a;
			land[a] += 1;//���� ���� �Է���7
		}
	}
	//�Ȱ��� ���� ���� ���� ���� ���� �͵��� �κ��丮�� �ִ� ������ ä���� ���
	//�׷��� ���ؼ� ���� �ľ� �ϴ� ���
	//�ְ��� ���̿� ���� ���� ���� �� ����..
	//1�̳� ��� �κ��丮���� ä�������ִ��� Ȯ�� �Ѵ�.->�ȵȴٸ� �������� �ٽû��� �ٽ� ���� �Ͱ� �������� ���� ���Ѵ�.
	//2�̻� �� ��� �������� �κ��丮�� ����(�κ��丮+1���ִ� �͵� ����)
	//�ּ��� �ð��� ���� �ϰ� ����
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

	//���� ������ Max����Min���� �������� ���� ������.
	while (Max != N*M) {
		//���� ���� ���� �͸� ���� �Ϳ� ���ߵ��� �Ѵ�.
		//�ٵ� �̷��� �ð��� �����ϸ� ��� ?
		//1.���� ���� ���� ���� ���� �Ϳ� ���ߵ����Ѵ�.
		//2.���� ���� ���� ���� ���� �Ϳ� ���ߵ��� �Ѵ�.
		//3.���� ä��� �ִ°� ���� B ���ǿ� �����ϸ� �İ� ���ǿ� �������� ���Ѵ�.�� �Ǵ�.
		if (B >= min) {
			
			if (Max_num < min_num) {
				B += min;//���� �İ� �κ��丮�� �ִ´�.
				time += min * 2;//�� ���� ���� ���� �� �Ǵ�.
				land[min_num] = 0;
				min_num--;
				land[min_num] += min;
			}
			else if (Max_num > min_num) {
				
				B -= min;//���� ä���.
				time += min;//�������� �ϳ��� ä�����ϱ� �ð��� ���� �Ѵ�.
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
			//���� ä������ ���� ������
		
			if (Max_num > min_num) {
				B += Max;//���� �İ� �κ��丮�� �ִ´�.
				time += Max * 2;//�� ���� ���� ���� �� �Ǵ�.
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
