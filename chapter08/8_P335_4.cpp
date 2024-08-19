#include<stdio.h>
#include<stdlib.h>

using namespace std;

// &�������Ҫ���� 
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int a[], int low, int high){
	// ��ȡ����±� (high - low + 1������)
	int root = low + rand() %(high - low + 1); 
	printf("a[root] = %d", a[root]);
	// ��������һ��
	swap(a[low], a[root]); 
	// i һ��ʼָ�� low λ��
	int i = low;
	// ��ȡ ��׼ֵ
	int p = a[low]; 
	// �ӵڶ�����ʼ���������� 
	for(int j = low + 1; j <= high; j++){
		if(a[j] < p){
			// i ���±� ���������ٽ��� 
			swap(a[++i], a[j]); 
		}
	} 
	// ����׼ֵ ���뵽 ����λ��
	swap(a[low], a[i]);
	printf("a[i] = %d	", a[i]);
	// ���� ��׼ֵ �±� 
	return i; 
}

int main(){
	
	int a[10] = {7, 5, 2, 9, 6, 30, 3, 8, 1};
	// int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i = Partition(a, 0, 8); 
	
	for(int i = 0; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	printf("i = %d", i);
	
	return 0;
} 
