#include<stdio.h>
#include <stdlib.h>

using namespace std;
/*
			һά�����±�� a[1] ��ʼ
			��ά�����±� �� b[1][1] ��ʼ 
*/ 

// ͨ���±� ���� a[i][j]��һά�����λ�� 
int value(int a[], int i, int j){
	// ���������򣨰������Խ��ߣ� 
	if(i >= j){
		return a[(i*(i-1))/2 + j];
	}
	// ���������򣨲��������Խ��ߣ�
	else{
		return a[(j*(j-1))/2 + i];
	}
}

//    �ѵ� 
void Mult(int a[], int b[], int c[4][4], int n){
	int i, j, k,sum;
	// i = 0 ��ʾ a���� ��һ����� 
	for(i = 1; i <= n; i++){
		// j = 3 ��ʾ b���� ��������� 
		for(j = 1 ; j <= n; j++){
			sum = 0;
			for(k = 1; k <= n; k++){
				sum = sum + value(a, i, k) * value(b, k, j);
			}
			// �� ÿһ�� �� ÿһ�� �� �� ��ֵ 
			c[i][j] = sum;
		}
		
	}
}

void Add(int a[], int b[], int c[4][4], int n){
	int i, j;
	// i = 0 ��ʾ ���� ��һ�� 
	for(i = 1; i <= n; i++){
		// j = 3 ��ʾ ���� ������
		for(j = 1 ; j <= n; j++){
			c[i][j] = value(a, i, j) + value(b, i, j);
		}
	}
}

int main(){
	// һά����洢 �Գƾ���������Ԫ�� 
	int a[7] = {0, 1, 2, 3, 1, 2, 3};
	int b[7] = {0, 1, 1, 2, 2, 3, 3};
	
	int c[4][4];
	int d[4][4]; 
	
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			c[i][j] = 0;
			d[i][j] = 0;
		}
	}
	
	Add(a, b, c, 3);
	
	Mult(a, b, d, 3);
	
	printf("ϡ�����ӷ���\n"); 
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			printf("%d	", c[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("ϡ�����˷���\n"); 
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			printf("%d	", d[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
