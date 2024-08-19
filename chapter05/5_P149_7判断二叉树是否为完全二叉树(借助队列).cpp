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

bool isCompleteBinaryTree(tree t){
	Queue q;
	InitQueue(q);
	// ���� 
	if(t == NULL){
		return true;
	}
	// ֻ�� ����� 
	if(t->lchild == NULL && t->rchild == NULL){
		return true;
	}
	// flag Ϊ true ��ʾ��֮ǰ�����Ľ�� �������Һ���  
	bool flag = true;
	// ����� ��� 
	treenode *p = t;
	EnQueue(q, p);
	
	// ���в�Ϊ��ʱ��whileִ�� 
	while(!isEmpty(q)){
		DeQueue(q, p);
		
		if(!p->lchild){ // ȱ ���� 
			flag = false;
			if(p->rchild){
				// ȱ ���ӣ� �� �Һ��ӣ�������ȫ������ 
				return false;
			}
		}
		// ��ǰ��� �� ���� 
		else{
			// flag == true����ʾ ֮ǰ������ ȱ���� ��� 
			if(flag){
				EnQueue(q, p->lchild); // ���� ����
				 
				if(p->rchild){
					// �Һ��� ���� 
					EnQueue(q, p->rchild);
				}
				else{
					// �����ӣ����Һ��� 
					flag = false;
				} 
			} 
			// ֮ǰ���� ȱ���ӵĽ�㣬���ýڵ��ִ��ں��ӽڵ�
			// �� �ö�����һ�����Ƕ����� 
			else{
				return false; 
			} 
		} 
	}
	return true; 
}

void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}	
}

int main(){
	
	tree t;
	// ABD##E##CF##G##
	buildtree(t);
	
	disp(t);
	
	if(isCompleteBinaryTree(t)){
		printf("yes!!!");
	}
	else{
		printf("no!!!");
	}
	
	return 0;
} 
