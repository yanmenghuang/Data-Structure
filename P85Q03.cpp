#include<stdio.h>
#include <stdlib.h>

#define Max 10
typedef struct{
	int data[Max];
	int top; // ���ܸ�ֵ ��Java���ԣ���̬����飩 
}stack;

// �ж�ջ�� 
bool isEmpty(stack s){
	if(s.top == -1){
		return true;
	}
	return false;
}

// �ж�ջ�� 
bool isFull(stack s){
	if(s.top == Max-1){
		return true;
	}
	return false;
}

// ѹջ 
bool pushStack(stack &s, int x){
	if(isFull(s)){
		return false;
	}
	s.data[++s.top] = x;
	// printf("%d \n", s.data[s.top]);
	return true;
}

// ��ջ 
bool popStack(stack &s, int &x){
	if(isEmpty(s)){
		printf("ջΪ�գ�����\n");
		return false;
	}
	x = s.data[s.top--];
	return 1;
}

// ���ջ 
void display(stack &s){
	int top1 = s.top;
	if(top1 != -1){
		while(top1 != -1){
		printf("%d	", s.data[top1--]);
		}
	}
	else{
		printf("ջΪ�գ�����"); 
	}
	
}

// ��� 
int enterQueue(stack &s1, stack &s2, int x){
	if(!isFull(s1)){
		pushStack(s1, x);
		return 1;
	}
	else if(isFull(s1) && isEmpty(s2)){
		printf("�������޷����룡����");
		return 0; 
	}
    else if(isFull(s1) && !isEmpty(s2)){
    	while(!isEmpty(s1)){
    		popStack(s1, x);
    		pushStack(s2, x);
		}
		pushStack(s1, x);
	}
	
	return 1; 
}

// ���� 
int deleteQueue(stack &s1, stack &s2, int &x){
	if(!isEmpty(s2)){
		popStack(s2, x);
	}
	else if(isEmpty(s1)){
		printf("����Ϊ��");
	}
	
	else{
		while(!isEmpty(s1)){
			popStack(s1, x);
			pushStack(s2, x);
		}
		
		popStack(s2, x);
	}
}

// �ж� �����Ƿ�Ϊ�� 
bool isEmptyQueue(stack s1, stack s2){
	if(isEmpty(s1) && isEmpty(s2)){
		return true;
	}
	return false;
}

int main(void){
	
	stack s1, s2;
	s1.top = -1;
	s2.top = -1;
	
	for(int i = 0; i < Max; i++){
		pushStack(s1, i+1);
	}
	
	/*
	while(!isEmpty(s1)){
		printf("%d", s1.data[s1.top--]);
	}
	*/
	
	display(s1);
	printf("\n");
	// printf("%d", s1.top);
	int x = 0;
	int t = 100;
	while(!isEmptyQueue(s1, s2)){
		deleteQueue(s1, s2, x);
		printf("����Ԫ��Ϊ��%d\n", x);
	}
	
	enterQueue(s1, s2, t);
	
	printf("���ջ s1��");
	display(s1);
	
	deleteQueue(s1, s2, x);
	printf("����Ԫ��Ϊ��%d\n", x);
	
	printf("���ջ s2��");
	display(s2);
	
	
	return 0;
} 
