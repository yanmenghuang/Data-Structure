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

treenode* find(tree t, char k){
	treenode *p = t;
	// ����Ϊ�� ��ִ�� if ��� 
	if(p != NULL){
		// �˳�ѭ��ʱ�����ҵ� ������ 
		while(p->data != k){
			// ��ǰ���ֵ > ����ֵ 
			if(p->data > k){
				p = p->lchild;
			}
			// ��ǰ���ֵ < ����ֵ 
			else{
				p = p->rchild;
			}
		}
	}
	return p;
	
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	// ���ҽ�� G 
	treenode *p = find(t, 'G');
	printf("%c	", p->data);
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
}
