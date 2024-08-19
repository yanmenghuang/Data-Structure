#include<stdlib.h>
#include<stdio.h>

using namespace std;

// n��Ԫ�ظ���    ����ռ䣺n + 1 �� 
void insertSort(int a[], int n){
	int i, j; 
	for(i = 2; i <= n; i++){
		if(a[i] < a[i - 1]){
			// a[0] �ڱ������������ 
			a[0] = a[i];
			// j ָ�� �������е����һ��λ�� 
			j = i - 1;
			while(a[0] < a[j]){
				a[j + 1] = a[j];
				j--;
			}
			// �� ������Ԫ�� ����Ŀ��λ�� 
			a[j + 1] = a[0]; 
		}
	}
}

void insertSort2(int a[], int n){
	int i, j, low, high, mid; 
	for(i = 2; i <= n; i++){
		if(a[i] < a[i - 1]){
			// a[0] �ڱ������������ 
			a[0] = a[i];
			// j ָ�� �������е����һ��λ�� 
			j = i - 1;
			low = 1;
			high = i - 1;
			// ���ֲ��� ���Ҳ���λ�� 
			while(low <= high){
				mid = (low + high) / 2;
				if(a[0] < a[mid]){
					high = mid - 1;
				}
				else{
					low = mid + 1;
				}
			}
			
			for(j = i - 1; j >= high + 1; j--){
				a[j + 1] = a[j];
			}
			// �� ������Ԫ�� ����Ŀ��λ�� 
			a[high + 1] = a[0]; 
		}
	}
}

int main(){
	
	int a[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
	
	for(int i = 1; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	insertSort(a, 8);
	
	for(int i = 1; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
}
