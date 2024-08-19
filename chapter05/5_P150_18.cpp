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

tree pre;

// ����������
void InThread(tree &t){
	// ��� �ǿ� 
	if(t){
		// �������� ��Ҷ�ӽ��
		InThread(t->lchild); // ������������ 
		
		if(t->lchild == NULL){ // ���� Ϊ�� 
			t->ltag = 1;
			t->lchild = pre;
		} 
		else{ // ���� ��Ϊ�� 
			t->ltag = 0;
		} 
		if(pre != NULL && pre->rchild == NULL){ // ǰ����� ��Ϊ�� �� ���Һ��� 
			pre->rtag = 1; // ǰ������к�� 
			pre->rchild = t;  // �� ǰ�����Һ��� ָ�� ��ǰ��� 
		}
		// ����ǰ����� 
		pre = t;
		
		InThread(t->rchild); // ������������ 
	}
} 

// �������������� �� ��������� �� ǰ�� 
tree Inpostpre(tree t, treenode *p){
	// ���ָ��
	treenode *q;
	// �ýڵ����Һ��� ������� �Һ��� 
	if(p->rtag == 0){
		q = p->rchild;
	} 
	// �ýڵ����Һ��ӣ������� ������� �Һ���
	else if(p->ltag == 0){
		q = p->lchild; 
	}
	// �ýڵ��ǰ��Ϊ�� ��Ϊ��������ĵ�һ����㣬�ý���ں��������Ҳ�ǵ�һ����� �޺���ǰ�� 
	else if(p->lchild == NULL){
		q = NULL;
	}
	// �����������Һ��ӣ���������������ĵ�һ����㣩 
	else{
		// ������������������ 
		while(p->ltag == 1 && p->lchild != NULL){
			p = p->lchild;
		}
		if(p->ltag == 0){
			q = p->lchild;
		}
		else{
			// û�к���ǰ�� �����е�֧���� 
			q = NULL;
		}
	}
	// ���� Ŀ���� �� ǰ����� 
	return q; 
} 

int main(){
	
	tree t;
	// �������У�ABD##E##CF##G##
	// ABD##E##CF### (�����в���)
	buildtree(t);
	// ������ 
	InThread(t);
	// t, �������Һ��� 
	treenode *q = Inpostpre(t, t->rchild);
	if(q){
		printf("%c	", q->data); 
	}
	else{
		printf("��ǰ��");
	}
	
	/*
				A
			B		C
		  D   E   F    G
	*/
	 
	
	return 0;
}
