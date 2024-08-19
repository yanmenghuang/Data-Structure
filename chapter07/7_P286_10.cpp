#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

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

// �� �� �� С �������  ��  �� 
void Out(tree t, char k){
	if(t == NULL){
		return;
	}
	// ��������Ϊ�գ��ݹ���������� 
	if(t->rchild != NULL){
		Out(t->rchild, k);
	}
	
	// �����ֵ > K�������
	if(t->data >= k){
		printf("%c	", t->data);
	} 
	
	// ��������Ϊ�գ� �ݹ����������
	if(t->lchild != NULL){
		Out(t->lchild, k); 
	}	
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	
	Out(t, 'E');
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
	return 0;
}
