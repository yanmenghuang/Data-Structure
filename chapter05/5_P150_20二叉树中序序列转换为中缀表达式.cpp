#include<stdio.h>
#include <stdlib.h>

typedef struct treenode{
	char data;
	treenode *lchild, *rchild;
}treenode, *tree;

void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch =='#'){
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
		disp(t->lchild);
		printf("%c	", t->data);
		disp(t->rchild);
	}
} 

void toexp(tree t, int deep){
	if(t == NULL){
		return;
	}
	else if(t->lchild == NULL && t->rchild == NULL){
		// Ҷ�ӽڵ㣬��� ������ 
		printf("%c", t->data);
	}
	else{
		if(deep > 1){
			printf("(");	
		}
		
		// �ݹ������������deep + 1 
		toexp(t->lchild, deep+1);
		printf("%c", t->data);
		// �ݹ���������� 
		toexp(t->rchild, deep+1);
		
		if(deep > 1){
			printf(")");
		}
	}
}

int main(){
	tree t;
	//  +*a##b##-#-c##d## 
	buildtree(t);
	disp(t);
	printf("\n");
	toexp(t, 1); 
	/*
				+
			*		-
		  a  b         -
		  			  c  d
	*/
	
	return 0;
	
}
