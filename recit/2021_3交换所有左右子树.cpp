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
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}
 
void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}
	
} 

// ������������ 
void swap(tree &t){
	// ��� �ǿ� 
	if(t){
		// �ݹ齻�������� 
		swap(t->lchild);
		// �ݹ齻�������� 
		swap(t->rchild);
		// ���� �������������� 
		treenode* p = t->lchild;
		t->lchild = t->rchild;
		t->rchild = p;
	}
}

int main(){
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	
	swap(t);
	
	printf("������Ķ�����Ϊ��");
	disp(t); 
	
	/*
				F
			E		H
		 C        G    I
	  A    D
	    B
	*/
	
	return 0;
}
