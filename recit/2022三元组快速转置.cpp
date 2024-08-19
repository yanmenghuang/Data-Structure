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
 
// ��Ԫ�� ����ת��
// ʱ�临�Ӷȣ�O(���� A ������ + ���� A �ķ���Ԫ�ĸ���) 
void FastTransposeSMatrix(TSMatrix A, TSMatrix &B){
	
	int i, position, col;
	// ���� A m�С�n��  ת��Ϊ ���� B n�С�m�� 
	B.m = A.n;
	B.n = A.m;
	B.len = A.len;
	// ����Ԫ���� ��Ϊ 0 
	if(A.len != 0){ 
		// num���飺��¼ ���� A �� ÿһ�з���Ԫ���� 
		int num[Max];
		// cpot���飺��¼ ���� B �� ÿһ���׷���Ԫ���±� 
		int cpot[Max];
		// num ���� ��ʼ�� 
		for(i = 1; i <= A.n; i++){
			num[i] = 0;
		}
		// num[2] = 5����ʾ ���� A �У��� 2 �� �� 5 ������Ԫ 
		for(i = 1; i <= A.len; i++){
			++num[A.data[i].col]; 
		}
		
		// �� 1 ������Ԫ �� ��Ԫ�������е��±�Ϊ 1 
		cpot[1] = 1;
		for(col = 2; col <= A.n; col++){
			// cpot[5] = cpot[4] + num[4]; 
			// �����еĵ�һ������Ԫ���±� = �����еĵ�һ������Ԫ�±� + �����з���Ԫ���� 
			cpot[col] = cpot[col - 1] + num[col - 1];	
		}
		
		// i �������� ��Ԫ����� 
		for(i = 1; i <= A.len; i++){
			// ��ȡ ��ǰԪ�ص��б� 
			col = A.data[i].col;
			// ��ȡ ��ǰ�� �׷���Ԫ���±� 
			position = cpot[col];
			
			//  ��ǰ�� �׷���Ԫ ���и�ֵ 
			B.data[position].row = A.data[i].col;
			B.data[position].col = A.data[i].row;
			B.data[position].value = A.data[i].value;
			// ���� ��ǰ�е� �׷���Ԫ�� �±� 
			++cpot[col]; 
		}
	} 
}

// ��Ԫ������ 
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

// ��ӡ��Ԫ�� 
void printTSMatrix(TSMatrix T){
	for(int i = 1; i <= T.len; ++i ){
		printf("%d	%d	%d\n", T.data[i].row, T.data[i].col, T.data[i].value);
	}
}
 
int main(){

	TSMatrix A, B;
	inputTSMatrix(A);

	FastTransposeSMatrix(A, B);

	printf("\nԭʼ��Ԫ��Ϊ:\n");
	printTSMatrix(A);
	
	printf("\nת�ú�:\n");
	printTSMatrix(B);
	
	return 0;
}
