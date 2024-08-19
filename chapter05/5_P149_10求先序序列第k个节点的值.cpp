#include<stdio.h>
#include <stdlib.h>

typedef struct treenode{
	char data;
	struct treenode *lchild,*rchild;
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

// ������ ȫ�ֱ��� 
int i = 1;
// ��ȡ����ַ� ȫ�ֱ��� 
char ch; 

char PreOrder(tree t, int k){
	if(t == NULL){
		// û���ҵ�������һ�������ַ� 
		return '#';
	}
	if(i == k){
		return t->data;
	}
	// ���������� 
	i++;
	// ���������ݹ���� 
	ch = PreOrder(t->lchild, k);
	
	if(ch != '#'){
		// �� ������ �Ѿ��ҵ� �� k ����� 
		return ch;
	}
	// ���������ݹ���� 
	ch = PreOrder(t->rchild, k);
	
	// ���ܶ������ܽڵ���� < k��û���ҵ� 
	return ch;
	
} 

int main(){
	
	tree t;
	// ABD##E##CF##G##
	buildtree(t);
	
	printf("%c	", PreOrder(t, 5));
	
	return 0;
}
