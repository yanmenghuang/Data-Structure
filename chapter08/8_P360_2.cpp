#include<stdio.h>
#include<stdlib.h>

using namespace std;

// �������� ��˼�� 
void InsertSort(int a[], int m, int n){
	int i, j;
	for(i = m+1; i <= m+n; i++){
		// a[0] ��Ϊ�ڱ���ÿһ�˶���Ҫ���� a[0] = a[i]����ǰ������Ԫ�أ� 
		a[0] = a[i];
		// ���� a[j] > a[0]��Ԫ�غ��� 
		for(j = i-1; a[j] > a[0]; j--){
			a[j + 1] = a[j];
		}
		// ����ѭ����a[j] < a[0]���ڱ�����λ��Ϊ j + 1 
		a[j + 1] = a[0]; 
	}
}

int main(){
	
	int a[8] = {0, 1, 3, 5, 7, 2, 4, 9};
	
	InsertSort(a, 4, 3);
	
	for(int i = 1; i <= 7; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
}
