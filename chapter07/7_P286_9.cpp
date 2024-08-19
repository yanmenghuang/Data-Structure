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

// ��Сֵ����������������˽�� 
char Min(tree t){
	while(t->lchild != NULL){
		t = t->lchild;
	}
	return t->data;
}

// ���ֵ���������������Ҷ˽�� 
char Max(tree t){
	while(t->rchild != NULL){
		t = t->rchild;
	}
	return t->data;
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	
	char min = Min(t);
	char max = Max(t);
	
	printf("min = %c, max = %c", min, max);
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
	return 0;
}
