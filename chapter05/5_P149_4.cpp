#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 10

// ��α����� ������� 
// ���� + ջ 

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

// ������ 
void buildtree(tree &t){
	char ch;
	ch = getchar();
	
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

typedef struct stack{
	// ջ��������� ָ�� 
	struct treenode *data[Max];
	int top; 
}stack;

bool isEmptyStack(stack s){
	// ջΪ�� 
	if(s.top == -1){
		return true;
	}
	// ջ�ǿ� 
	return false; 
} 

bool isFullStack(stack s){
	// ջΪ�� 
	if(s.top == Max -1){
		return true;
	}
	// ջ���� 
	return false;
} 

bool enterStack(stack &s, treenode *p){
	if(isFullStack(s)){
		printf("ջ��");
		return false;
	}
	s.data[++s.top] = p;
	return true;
} 

bool outStack(stack &s, treenode *&p){
	if(isEmptyStack(s)){
		printf("ջ��");
		return false;
	}
	p = s.data[s.top--];
	return true;
}

typedef struct squeue{
	treenode *data[Max];
	// f:ͷָ�� r:βָ�� tag:�ж϶����Ƿ� �� �� �� 
	int f,r,tag;	
}squeue;

bool isEmptyQueue(squeue q){
	if(q.f == q.r && q.tag == 0){
		return true;
	}
	return false;
}

bool isFullQueue(squeue q){
	if(q.f == q.r && q.tag == 1){
		return true;
	}
	return false;
}

bool entersqueue(squeue &q, treenode *x){
	if(isFullQueue(q)){
		printf("����");
		return false;
	}
	q.data[q.r] = x;
	q.r = (q.r + 1) % Max;
	q.tag = 1;
	return true; 
}

// *& x �����Ҫ���أ�����ָ������ 
// &����ʾ ��� ��Ҫ���أ�*����ʾָ������ 
bool outsqueue(squeue &q, treenode* &x){
	if(isEmptyQueue(q)){
		printf("�ӿ�");
		return false;
	}
	x = q.data[q.f];
	q.f = (q.f + 1) % Max;
	q.tag = 0;
	return true;
}

void solve(tree t){
	stack s;
	squeue q;
	treenode *p;
	if(t){
		s.top = -1;
		q.f = q.r = 0;
		q.tag = 0; 
		// ��� 
		entersqueue(q, t);
		// �����зǿ�ʱ��whileѭ��ִ�� 
		// ��α��� 
		while(!isEmptyQueue(q)){
			// p ָ�� ������ӽڵ� 
			outsqueue(q, p); // ���� 
			enterStack(s, p); // ��ջ 
			// ��� ���Һ��Ӵ��ڣ��ֱ���� 
			if(p->lchild != NULL){
				entersqueue(q, p->lchild);
			}
			if(p->rchild != NULL){
				entersqueue(q, p->rchild);
			}
		}
		
		// �� ջ �ǿ�ʱ��whileѭ��ִ�� 
		while(!isEmptyStack(s)){
			outStack(s, p);
			printf("%c	", p->data); 
		} 
	}
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	solve(t);
	return 0;
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
}
