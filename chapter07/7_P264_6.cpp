#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

//   ����   ����Ԫ�ظ���   ����ֵ 
int Search(int a[], int n, int k){
	int i;
	for(i = 0; i < n; i++){
		if(a[i] == k){
			break;
		}
	}
	// i > 0�����ǵ�һ��Ԫ��  i < n���������д���Ԫ�� 
	if(i > 0 && i < n){
		int temp = a[i];
		a[i] = a[i-1];
		a[i-1] = temp;
		
		// ���ؽ������λ�� 
		return i-1;
	}
	else{
		// ����ʧ�� 
		return -1;
	} 
	
} 

int main(){
	
	int a[6] = {1, 3, 5, 7, 9, 11};
	
	int locate = Search(a, 6, 7);
	printf("%d	", locate);
	
	return 0;
} 
