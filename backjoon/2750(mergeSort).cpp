#include<stdio.h>
#pragma warning(disable:4996)

void mergeSort(int data[], int s, int e) {
	int tmp[10000];
	int i = s;
	int k = s;
	int m = (s + e) / 2;
	int j = m + 1;
	if (s >= e)return;//�ɰ� ������, �ǵ��ư���
	mergeSort(data, s, m);
	mergeSort(data, m + 1, e);
	while ((i <= m) && (j <= e)) {
		if (data[i] < data[j])
			tmp[k++] = data[i++];
		else
			tmp[k++] = data[j++];
	}
	while (i <= m)tmp[k++] = data[i++];//������ ����
	while (j <= e)tmp[k++] = data[j++];//������ ����
	for (i = s;i <= e;i++)data[i] = tmp[i];//����
}

int main() {
	int N,h=2;
	int arr[1000];
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}
	mergeSort(arr,0,N-1);//N==sizeof(arr)/sizeof(int):�迭�� ũ�� ->�ε����� ���⼭ �ϳ� �����ϱ� -1
	
	for (int i = 0;i < N;i++) {
		printf("%d\n", arr[i]);
	}
	//scanf("%d", &N);
	return 0;
}
/*nlogn�� �ð� ���⵵�� ������ ���� �˰��� ���� �˾ƺ���
nlog n �� �־��� �ð����⵵�� ������ ��->O(n log n)�� ���� �˰��򿡴� Merge Sort ,Heap Sort�� ����
������->���� ������ ���� ����
=>�պ����ĵ� ��������
���պ������� ���Ҹ� �ϳ��� ������ ������ �� ���� �� ���Ҹ� �ٽ� �պ��ϴ� ���� ���
1.����Ʈ�� ���̰� 1�� �ɶ����� ������ �߰� ������->����
2.�� ������ ���ٸ�, �����͸� ��ġ�µ�(Merge),�����ϸ鼭 ��ģ��.
�⺻������ ���������� ����Լ��� �����Ѵ�.
������ �ɰ��� �ٽ� ����Լ� ȣ���ϰ� ȣ���� ����� ������ ������ �Ѵ�.
*/