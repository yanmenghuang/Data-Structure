#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

// �������� ˼�� 
void Move(int a[], int n){
	int i = 0, j = n-1;
	// ѭ���������� 
	while(i < j){
		// ��ǰ���� �� ż��λ�� 
		while(i < j && a[i] % 2 == 1){
			i++;
		} 
		// �Ӻ���ǰ �� ����λ�� 
		while(i < j && a[j] % 2 == 0){
			j--;
		}
		// ż��λ�� �� ����λ�� ǰ�� 
		if(i < j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp; 
			// �� �м� ��£
			i++;
			j--; 
		}	
	}
} 

void Move_two(int a[], int n){
	int i = 0;
	for(int j = 0; j < n; j++){
		if(a[j] % 2 == 1){
			swap(a[j], a[i]);
			i++;
		}
	}
}

int main(){
	
	int a[10] = {7, 5, 9, 2, 6, 4, 3, 8, 1};
	
	Move(a, 9);
	
	for(int i = 0; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
} 
