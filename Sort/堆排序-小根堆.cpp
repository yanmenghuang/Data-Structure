#include<stdio.h>
#include<stdlib.h>

#define Max 20 

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

// end��Ԫ�ظ��� 
void HeapAdjust(int r[], int k, int end){
	int i = k; // ���ڵ� 
	int j = 2 * k; // ���ӽڵ� 
	while(j <= end){
		// j < end����ǰ�ýڵ� ���Һ���
		// r[j] > r[j + 1]��������ֵ > ������ֵ 
		if(j < end && r[j] > r[j + 1]){
			// j ָ�� ��������ֵ��С�ߣ������� 
			j++; 
		}
		// �����ֵ > ���ӽ��ֵ 
		if(r[i] > r[j]){
			swap(r[i], r[j]);
		}
		// ���½��е��� 
		i = j;
		j = 2 * i;
	}
}

void HeapSort(int a[], int n, int b[], int num){
	int k;
	// ���� ����� 
	for(k = n / 2; k >= 1; k--){
		HeapAdjust(a, k, n);
	}
	// ���� �����µ����� 
	for(k = 1; k <= num; k++){
		b[k] = a[1];
		// �� ��ǰ�ĶѶ� �� ��ǰ�����������һ�� ���н��� 
		swap(a[1], a[n - k + 1]);
		
		// 1����Ҫ�����ĸ����
		// n - k����Ҫ������Ԫ�ظ��� 	
		HeapAdjust(a, 1, n - k);
	}
} 

int main(){
	// a[0] δʹ�� 
	int a[7] = {0, 28, 25, 16, 36, 18, 32};
	int b[Max];
	int num;
	printf("������Ҫ�ҵ���С���ĸ�����");
	scanf("%d", &num);
	
	for(int i = 1; i < 7; i++){
		printf("%d	", a[i]);
	}
	printf("\n");
	
	HeapSort(a, 6, b, num);
	
	for(int i = 1; i <= num; i++){
		printf("%d	", b[i]);
	}
	
	return 0;
}
