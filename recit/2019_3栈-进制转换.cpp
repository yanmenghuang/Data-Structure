#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 10 

typedef struct{
	int data[Max];
	int top;
}Stack;

void InitStack(Stack &s){
	s.top = -1;
}

bool isEmpty(Stack s){
	if(s.top == -1){
		return true;
	}
	return false;
}

bool isFull(Stack s){
	if(s.top == Max - 1){
		return true;
	}
	return false;
}

void Push(Stack &s, int value){
	if(isFull(s)){
		printf("ջ��"); 
		return; 
	}
	s.data[++s.top] = value;
	return;
}

void Pop(Stack &s, int &value){
	if(isEmpty(s)){
		printf("ջ��!");
		return;
	}
	value = s.data[s.top--];
	return;
}

void Conversion(int m, int n){
	Stack s;
	InitStack(s);
	while(m){
		Push(s, m % n);
		m = m / n;
	}
	
	while(!isEmpty(s)){
		int ans;
		Pop(s, ans);
		printf("%d", ans);
	}
}

int main(){
	int N;
	printf("��������������");
	scanf("%d", &N);
	
	printf("ת�����Ϊ��");
	Conversion(N, 8);
	return 0;
}
