#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct {
	// C ���� ���ܽ��� ��̬��ʼ�� 
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int length = 8;
}ST;

int Bin(ST s, int ans, int low, int high){
	// �ݹ�����
	if(low > high){
		return 0;
	} 
	// �� �м��±� 
	int mid = (low + high) / 2;
	// ����ֵ >  �м�ֵ 
	if(ans > s.a[mid]){
		return Bin(s, ans, mid + 1, high);
	}
	// ����ֵ <  �м�ֵ 
	else if( ans < s.a[mid]){
		return Bin(s, ans, low, mid - 1);
	}
	// ��� ֱ�ӷ��ظ�ֵ���±� 
	else{
		return mid;
	}
	
	return mid;
}

int main(){
	ST s;
	// ��ʼ���ṹ�� 
	
	
	int ans = Bin(s, 3, 1, 8);
	printf("%d	", ans); 
	return 0;
}
