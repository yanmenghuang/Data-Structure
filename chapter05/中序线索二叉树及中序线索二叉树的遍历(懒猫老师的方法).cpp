#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
	// tag = 0�������Һ���  tag = 1�������Һ��� 
	int ltag, rtag;
}treenode, *tree; 

void buildtree(tree &t){
	char ch;
	// ���� 
	cin>>ch;
	
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		t->ltag = 0;
		t->rtag = 0;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// ����Ϊȫ�ֱ��� 
tree pre;

// ����������
void InThread(tree t){
	// ��� �ǿ� 
	if(t){
		// �������� ����������ĵ�һ����� 
		InThread(t->lchild); // ������������ 
		
		if(t->lchild == NULL){ // ���� Ϊ�� 
			t->ltag = 1;
			// �� ����ָ�� ָ�� �������ʱ�� ǰ����� 
			t->lchild = pre;
		} 
		
		if(pre != NULL && pre->rchild == NULL){ // ǰ����� ��Ϊ�� �� ǰ��������Һ��� 
			pre->rtag = 1; // ǰ������к�� 
			pre->rchild = t;  // �� ǰ�����Һ���ָ�� ָ�� ��ǰ��� 
		}
		// ����ǰ����� 
		pre = t;
		
		InThread(t->rchild); // ������������ 
	}
} 

treenode *q;

// ���������� �Һ�� 
treenode* ThreadNext(tree t){
	// �ұ�־Ϊ 1����ֱ�ӵõ� ��̽�� 
	if(t->rtag == 1){
		q = t->rchild;
	}
	// �ұ�־Ϊ 0���� ���Ϊ �����������½ǽ�� 
	else{
		q = t->rchild;
		// ���� �����½�� 
		while(q->ltag == 0){ // q ������ 
			q = q->lchild;
		}
	}
	return q; 
} 

void visit(treenode *p){
	printf("%c	", p->data);
}

// p->tag = 1����ָ���������
// p->tag = 0���ý�����Һ��ӣ�������Ϊ �������е������½�� 
void ThreadInOrder(tree t){
	treenode *p;
	// ��Ϊ�� 
	if(t == NULL){
		return;
	}
	p = t;
	// ������������ĵ�һ����� 
	while(p->ltag == 0){ // p ������ 
		p = p->lchild;
	}
	// ���ʵ�һ����� 
	printf("��ǰ��㣺%c	", p->data);
	visit(p);
	// ��ǰ p�����ں�̣����η��ʺ�̽�� 
	while(p->rchild != NULL){
		p = ThreadNext(p);
		visit(p);
	}
} 

int main(){
	
	tree t;
	// �������У�ABD##E##CF##G##
	// ABD##E##CF### (�����в���)
	buildtree(t);
	// ������ 
	InThread(t);
	
	// ��������������� 
	ThreadInOrder(t);
	
	/*
				A
			B		C
		  D   E   F    G
	*/
	 
	return 0;
}
