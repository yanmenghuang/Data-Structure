#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

// ��� �� ������������ ��� 

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

int Search(tree t, char k){
	
	treenode *p = t;
	int depth = 1;
	while(p != NULL){
		if(p->data == k){
			return depth;
		}
		else if(p->data > k){
			p = p->lchild;
			depth++;
		}
		else{
			p = p->rchild;
			depth++;
		}
	}
	// whileѭ���˳����򲻴���ָ���ڵ� 
	return 0;
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	// ���ҽ�� B 
	int depth = Search(t, 'B');
	printf("%d	", depth);
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
}
