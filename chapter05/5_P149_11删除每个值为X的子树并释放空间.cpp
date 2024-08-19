#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild,*rchild;
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

// �ݹ� ɾ����� 
void Release(tree &t){
	if(t){
		Release(t->lchild);
		Release(t->rchild);
		free(t); // free����ʾ�ÿռ䲻ʹ�� 
	}
}

// ������� 
void delete_x(tree &t, char x){
	if(t == NULL){
		return;
	}
	if(t->data == x){
		// �ݹ��ͷŽ�� 
		Release(t);
		// �ֶ����ýڵ�Ϊ NULL�������ڴ��һ���ͷ� 
		t = NULL; 
	}
	
	if(t != NULL){
		// �ݹ���� ȥ��������ɾ�� ֵΪX �Ľڵ� 
		delete_x(t->lchild, x);
		delete_x(t->rchild, x);
	}
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
	// ǰ�����У�ABD##E##CF##G##
	// �������У�FECA#B##D###HGJ##K##IL##M## 
	buildtree(t);
	disp(t);
	printf("\n");
	delete_x(t, 'H');
	
	disp(t);
	/*
					F
				E		 H
			 C        G     I
		  A    D    J   K  L M
		   B
	*/
	return 0;
}
