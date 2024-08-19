#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define Max 50 

typedef struct {
	int data[Max];
	// ע��д��������ջ��ָ�� 
	int top[2];
}stack1;

stack1 s; 
// ���� i����ʾҪ��ջ�� x����ʾ��ѹ��Ԫ�� 
bool push(int i, int x){
	if(i != 0 && i != 1){
		printf("��ջ��");
		return false;
	}
	
	if(s.top[1] - s.top[0] == 1){
		printf("ջ����");
		return false;
	}
	
	if(i == 0){
		// 0��ջ���� topָ���������ٸ�ֵ 
		s.data[++s.top[0]] = x;
	}
	else{
		// 1��ջ���� topָ���Լ����ٸ�ֵ 
		s.data[--s.top[1]] = x;
	}
	
	return true;
}

bool pop(int i, int &x){
	if(i != 0 && i != 1){
		printf("��ջ��");
		return false;
	}
	
	if(i == 0){
		if(s.top[0] == -1){
			printf("0��ջ�գ�");
			return false;
		}
		else{
			// �ȸ�ֵ���� ջ��ָ���Լ� 
			x = s.data[s.top[0]--];
			return true;
		}
	}
	else{
		if(s.top[1] == Max){
			printf("1��ջ�գ�");
			return false;
		}
		else{
			// �ȸ�ֵ���� ջ��ָ���Լ� 
			x = s.data[s.top[0]++];
			return true;
		}
	}
}

int main(){
	s.top[0] = -1;
	s.top[1] = Max;
	
	if(push(0, 5)){
		printf("0��ջ��ջ�ɹ���");
	}
	
	int x;
	
	if(pop(0, x)){
		printf("%d\n", x);
	}
	
	if(pop(0, x)){
		printf("%d", x);
	}
	
	return 0;
}
