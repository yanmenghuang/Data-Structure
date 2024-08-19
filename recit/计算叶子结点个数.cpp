#include<stdio.h>
#include <stdlib.h>
using namespace std;

// ���ṹ��
typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

void buildtree(tree &t){
	// �������� ���� 
	char ch;
	// getchar����ȡ������ַ���ÿ�λ�ȡһ�� 
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	} 
	else{
		// �����ڴ�ռ�����
		t = (treenode *) malloc(sizeof(treenode));
		// ����㸳ֵ 
		t->data = ch;
		// �� ���Һ��� ��Ϊ ��
		t->lchild = NULL;
		t->rchild = NULL;
		
		// �ݹ�� ���Һ��Ӹ�ֵ
		buildtree(t->lchild);
		buildtree(t->rchild); 
	}
}

int Count(tree t){
	if(t == NULL){
		return 0;
	}
	else if(t->lchild == NULL && t->rchild == NULL){
		return 1;
	}
	int c1 = Count(t->lchild);
	int c2 = Count(t->rchild);
	return c1 + c2;
	
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
	// ǰ�����У�FECA#B##D###HG##I## 
	buildtree(t);
	printf("%d ", Count(t)); // 9 �� 
	return 0;
		/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
} 
