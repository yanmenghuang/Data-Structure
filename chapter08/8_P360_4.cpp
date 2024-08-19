#include<stdio.h>
#include<stdlib.h>

using namespace std;

// �� ���һ��Ԫ�� ���� ������ ��ȷλ�� 

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

int QuickSort(int a[], int low, int high){
	int i = high;
	int pivot = a[high];
	
	for(int j = high - 1; j >= 0; j--){
		// ���� ��׼ֵ 
		if(a[j] > pivot){
			// i ���Լ����ٽ��н��� 
			swap(a[--i], a[j]);
		}
	}
	// for ѭ������ʱ��i ��ָ��Ԫ�� ���� ��׼ֵ 
	// �� ���һ��Ԫ�� ���õ� ��ȷλ�� 
	swap(a[high], a[i]);
	// ���ػ�׼ֵ�±� 
	return i;
} 

int main(){
	
	int a[5] = {3, 6, 7, 4, 5};
	// 3  6  7  4  5
	// 3   6   4   7   5
	//  3   4    6    7    5   ��ʱ i ָ�� 6���� a[i] �� a[high] ���н���
	//  3   4    5    7    6 
	int i = QuickSort(a, 0, 4);
	printf("%d", i);
	printf("\n");
	
	for(int i = 0; i < 5; i++){
		printf("%d	", a[i]);
	} 
	return 0;
} 
