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

int level(tree t, treenode *k){
	int degree = 0;
	treenode *p = t;
	// ����Ϊ�� ��ִ�� if ��� 
	if(t != NULL){
		degree++;
		while(p->data != k->data){
			degree++;
			// ��ǰ���ֵ > ����ֵ 
			if(p->data > k->data){
				p = p->lchild;
			}
			// ��ǰ���ֵ < ����ֵ 
			else{
				p = p->rchild;
			}
		}
	}
	return degree;
	
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	// ���ҽ�� B 
	int l = level(t, t->lchild->lchild->lchild->rchild);
	printf("%d	", l);
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
}
