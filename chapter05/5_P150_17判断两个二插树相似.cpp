#include<stdio.h>
#include <stdlib.h>
#include<iostream> 

using namespace std;

typedef struct treenode{
	char data;
	treenode *lchild,*rchild;
}treenode, *tree;

void buildtree(tree &t){
	char ch;
	ch = getchar(); 
	
	if(ch == '#'){
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

bool similar(tree t1, tree t2){
	// ���� ��Ϊ �գ����� 
	if(t1 == NULL && t2 == NULL){
		return true;
	}
	// ֻ��һ�� Ϊ �գ������� 
	else if(t1 == NULL || t2 == NULL){
		return false;
	}
	// ���� ����Ϊ �գ��ݹ���� �������� 
	else{
		// �� ������������ �ݹ� 
		bool leftS = similar(t1->lchild, t2->lchild);
		// �� ������������ �ݹ� 
		bool rightS = similar(t1->rchild, t2->rchild);
		
		// ֻ�� �������������������ƣ����������� 
		// 1 && 1 = 1; 1 && 0 = 0; 0 && 1 = 0; 0 && 0 = 0; 
		return leftS && rightS;
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
	
	tree t1, t2;
	buildtree(t1); // AB###
	buildtree(t2); // C#D## 
	
	disp(t1);
	printf("\n");
	disp(t2);
	if(similar(t1, t2)){
		printf("����");
	}
	else{
		printf("������");
	}
	return 0;
}
