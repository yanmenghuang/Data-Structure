#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int a[], int n){
	int exchange = n - 1;
	while(exchange){
		int bound = exchange;
		// exchange �� for ѭ������������δ 0����û�н��н��� 
		exchange = 0;
		for(int i = 0; i < bound; i++){
			if(a[i] > a[i + 1]){
				swap(a[i], a[i + 1]);
				// exchange ��¼ ����λ�������±� 
				exchange = i;
			}
		}
	}
}

void bubbleSort2(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		bool flag = false;
		// ÿһ�� �� ��ǰ���ֵ �ŵ� ��ǰ�����
		// ע�⣺j < n - i - 1 
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		// ���˱��� û�н��н�����˵�����Ѿ����� 
		if(flag == false){
			return;
		}
	}
}

int main(){
	
	int a[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	
	for(int i = 0; i < 8; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	bubbleSort2(a, 8);
	
	for(int i = 0; i < 8; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
}
