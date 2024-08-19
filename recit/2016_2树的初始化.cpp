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

// ���� 
void PreOrder(tree t){
	if(t){
		printf("%c	", t->data);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

// ���� 
void InOrder(tree t){
	if(t){
		InOrder(t->lchild);
		printf("%c	", t->data);
		InOrder(t->rchild); 
	}
}

// ���� 
void PostOrder(tree t){
	if(t){
		PostOrder(t->lchild);
		PostOrder(t->rchild);
		printf("%c	", t->data);
	}
}

void Release(tree &t){
	if(t){
		Release(t->lchild);
		Release(t->rchild);
		// free����ʾ�ÿռ䲻ʹ�� 
		free(t); 
		// ���ýڵ�Ϊ NULL�������ڴ��һ���ͷ� 
		t = NULL;
	}
}

int main(){
	tree t;
	// ǰ�����У�FECA#B##D###HG##I## 
	buildtree(t);
	
	Release(t);
	
	return 0;
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
} 
