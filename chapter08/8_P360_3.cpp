#include<stdio.h>
#include<stdlib.h>

using namespace std;

void countSort(int a[], int b[], int n){
	// ����ÿһ��
	int count;
	for(int i = 0; i < n; i++){
		// �� ��ÿ��Ԫ��С�ĸ��� 
		count = 0;
		for(int j = 0; j < n; j++){
			if(a[j] < a[i]){
				count++;
			}
		}
		b[count] = a[i];  
	} 
}

int main(){
	
	int a[6] = {3, 5, 7, 2, 4, 9};
	
	int b[6];
	
	countSort(a, b, 6);
	
	for(int i = 0; i < 6; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i < 6; i++){
		// b[5] = 9����ʾ �� Ԫ�� 9 С�ĸ����� 5 ��  
		printf("�� %d С�ĸ����У�%d\n", b[i], i);
	}
	
	return 0;
}
