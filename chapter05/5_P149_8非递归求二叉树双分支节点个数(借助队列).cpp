#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 20

/*
		�ж��Ƿ�Ϊ����������
		1�����ڵ������ӣ���ض����Һ���
		2�����ڵ��޺��ӣ����α����У���̽ڵ�Ҳ���޺��� 
*/

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
		t = (treenode *) malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

void disp(tree t){
	if(t != NULL){
		printf("%c	", t->data);
		
		disp(t->lchild);
		disp(t->rchild);
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

int num(tree t){
	Queue q;
	InitQueue(q);
	
	if(t == NULL){
		return 0;
	}
	int count = 0;
	treenode *p = t;
	EnQueue(q, p);
	
	while(!isEmpty(q)){
		DeQueue(q, p);
		// ��ǰ�ڵ����Ҷ��ǿգ�˫��֧�ڵ���� + 1 
		if(p->lchild != NULL && p->rchild != NULL){
			count++;
		} 
		if(p->lchild != NULL){
			EnQueue(q, p->lchild);
		}
		if(p->rchild != NULL){
			EnQueue(q, p->rchild);
		} 
	}
	return count; 
}

int main(){
	
	tree t;
	// ǰ�����У�FECA#B##D###HG##I## 
	buildtree(t); 
	disp(t);
	printf("\n");
	
	printf("�����������Һ�������%d	", num(t));
	
	return 0;
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
}
