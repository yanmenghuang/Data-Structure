#include<stdio.h>
#include<stdlib.h>

using namespace std;

// &�������Ҫ���� 
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

// low �� 0 ��ʼ 
int min_k(int a[], int low, int high, int k){
	// �������� �����㷨 
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
	
	// �����±� �� 0 ��ʼ 
	// ��� ��׼λ�� == k - 1����׼���� �� k С
	if(i == k - 1){
		return a[i];
	} 
	// ��� ��׼λ�� > k - 1���ڻ�׼��ߵݹ�ȥ�� �� k С
	else if(i > k - 1){
		return min_k(a, low, i -1, k);
	}
	// ��� ��׼λ�� < k - 1���ڻ�׼�ұߵݹ�ȥ�� �� k С
	else{
		return min_k(a, i + 1, high, k);
	}
}

int main(){
	
	int a[10] = {0, 7, 5, 9, 2, 6, 4, 3, 8, 1};
	
	int k = min_k(a, 0, 9, 1);
	
	printf("%d", k); 
	
	return 0;
}
