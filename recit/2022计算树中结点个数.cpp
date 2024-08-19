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
	int countl = Count(t->lchild);
	int countr = Count(t->rchild);
	// ���ӽ����� + �Һ��Ӹ��� + ��ǰ���ڵ� 
	return countl + countr + 1;
	
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
