#include <stdio.h>
#include <stdlib.h>
#define Max 100

//��Ԫ��ṹ��Ķ��� 
typedef struct{
	// ����Ԫ�����С������� 
	int row, col;
	// ����Ԫ��ֵ 
	int value;		
}Triple;
 
//��Ԫ�������Ķ��� 
typedef struct{
	// data[0] δʹ�� 
	Triple data[Max];
	// ����Ϊ m�С�n��  
	int m, n;
	// �������Ԫ����
	int len; 
}TSMatrix;
 
//ʵ��ת�� 
void TransposeSMatrix(TSMatrix A, TSMatrix &B){
	
	int i, col;
	// ���� A m�С�n��  ת��Ϊ ���� B n�С�m�� 
	B.m = A.n;
	B.n = A.m;
	B.len = A.len;
	// q ��ʾTriple�����±꣬�� 1 ��ʼ��data[0] δʹ��  
	int q = 1;
	
	// col <= A��������������Ƶ��� ��ǰ�������� A�������  
	for(col = 1; col <= A.n; ++col){	
		// ÿһ�� ����һ�� Triple���� 
		for(i = 1; i <= A.len; ++i){
			// �� ��ǰԪ�ص��б� == col������ A �ĵ� col �У� 
			if(A.data[i].col == col){
				// A���� ת��Ϊ B���� 
				B.data[q].row = A.data[i].col;
				// A���� ת��Ϊ B���� 
				B.data[q].col = A.data[i].row;
				// �� ����Ԫ ��ֵ 
				B.data[q].value = A.data[i].value;
				// �����±����һλ 
				++q;
			}
		}
	} 
}

void inputTSMatrix(TSMatrix &T){
	int i, j, value, k; 
	printf("���������������������");
	scanf("%d %d", &T.m, &T.n);
	printf("��������Ԫ�� ����Ԫ������");
	scanf("%d", &T.len);
	for(k = 1; k <= T.len; k++){
		printf("������� %d ������Ԫ���� �� ֵ��", k);
		scanf("%d %d %d", &i, &j, &value);
		T.data[k].row = i;
		T.data[k].col = j;
		T.data[k].value = value;
	}
}

void printTSMatrix(TSMatrix T){
	for(int i = 1; i <= T.len; ++i ){
		printf("%d	%d	%d\n", T.data[i].row, T.data[i].col, T.data[i].value);
	}
}

int main(){

	TSMatrix A,B;
	inputTSMatrix(A);

	TransposeSMatrix(A, B);

	printf("\nԭʼ��Ԫ��Ϊ:\n");
	printTSMatrix(A);
	
	printf("\nת�ú�:\n");
	printTSMatrix(B);
	
	return 0;
}
