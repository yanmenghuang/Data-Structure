#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 20

// �ǵݹ����������ĸ߶�

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

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

typedef struct{
	treenode *data[Max];
	int front;
	int rear;
	int tag;
}Queue;

void InitQueue(Queue &q){
	q.front = 0;
	q.rear = 0;
	q.tag = 0;
}

bool isFull(Queue q){
	if(q.front == q.rear && q.tag == 1){
		return true;
	}
	return false;
}

bool isEmpty(Queue q){
	if(q.front == q.rear && q.tag == 0){
		return true;
	}
	return false;
}

void EnQueue(Queue &q, treenode *x){
	if(isFull(q)){
		printf("����\n");
		return;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % Max;
	q.tag = 1;
}

void DeQueue(Queue &q, treenode *&x){
	if(isEmpty(q)){
		printf("�ӿ�\n");
		return;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % Max;
	q.tag = 0;
}

int dept(tree t){
	// ��Ϊ�� �߶�Ϊ0 
	if(!t){
		return 0;
	}
	Queue q;
	InitQueue(q);
	treenode *p = t; 
	int depth = 0;
	
	EnQueue(q, p);
	printf("�ڵ� %c	���\n", p->data);
	int Latest = q.rear;
	
	// ���зǿ� 
	while(!isEmpty(q)){
		DeQueue(q, p);
		printf("�ڵ� %c	����\n", p->data);
		// ���Һ��Ӳ�Ϊ�գ��ֱ���� 
		if(p->lchild){
			EnQueue(q, p->lchild);
			printf("�ڵ� %c	���\n", p->lchild->data);
		}
		if(p->rchild){
			EnQueue(q, p->rchild); 
			printf("�ڵ� %c	���\n", p->rchild->data);
		}
		// f == L����ʾ��������ǰ�� �� ���� ��㣬
		// ��ǰ�����һ�����нڵ㶼�Ѿ���� 
		if(q.front == Latest){
			// �߶� + 1 
			depth++;
			// L ָ����һ�� �� ���� ��� 
			Latest = q.rear;
		}
	}
	return depth; 
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	printf("���ߣ�%d", dept(t));
	
	return 0;
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
} 





