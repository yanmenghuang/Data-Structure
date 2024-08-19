#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void Move(int a[], int n){
	// ����ָ���ָ�� ��ʼ�� 
	int i = 0, j = 0, k = n-1;
	
	while(j <= k){
		int temp;
		
		if(a[j] > 0){
			temp = 1;
		}
		else if(a[j] == 0){
			temp = 0;
		}
		else {
			temp = -1;
		}
		// switch �ж� a[j] ��ֵ 
		switch(temp){
			// �������� a[i] ����
			case -1: swap(a[i], a[j]); i++;j++;break;
			// �㣺����ָ�� + 1
			case 0: j++; break;
			// �������� a[k] ����
			// ע�⣺j ���� + 1,��Ϊ���ܽ���������ֵΪ ��ֵ 
			case 1:swap(a[j], a[k]); k--; break; 
		}
	}
}

int main(){
	
	int a[9] = {8, -1, -2, 0, 0, 5, -6, -10};
	
	Move(a, 8);
	
	for(int i = 0; i < 8; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
} 
