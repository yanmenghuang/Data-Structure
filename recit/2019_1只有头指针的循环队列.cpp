#include<stdio.h>
#include<stdlib.h>
// ����������� 
#define Max 10

using namespace std;

typedef struct{
	int data[Max];
	// ͷָ�� 
	int front;
	// ������ Ԫ�ظ��� 
	int count;
}Qu;

void InitQueue(Qu &q){
	q.front = 0;
	q.count = 0;
} 

void EnQueue(Qu &q, int value){
	if(q.count == Max){
		printf("����");
		return;
	}
	// ��� 
	q.data[(q.front + q.count) % Max] = value;
	// ����Ԫ�� + 1 
	q.count++;
	return;	
}

void DeQueue(Qu &q, int &value){
	if(q.count == 0){
		printf("�ӿ�");
		return;
	}
	// ���� 
	value = q.data[q.front];
	// ����Ԫ�� - 1 
	q.count--;
	// ͷָ����� 
	q.front = (q.front + 1) % Max;
}

int main(){
	
	Qu q;
	InitQueue(q);
	
	return 0;
} 
