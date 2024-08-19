#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

// �ǵݹ����������ĸ߶�

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
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
} 

int dept(tree t){
	// ��Ϊ�� �߶�Ϊ0 
	if(!t){
		return 0;
	}
	// ���У���������� ���� 
	treenode *q[10]; 
	// tree q[10];
	int f = -1, r = -1;
	int Latest = 0, depth = 0;
	
	q[++r] = t;
	// ָ�� p ָ����ӽ�� 
	treenode *p; 
	// tree p;
	// ���зǿ� 
	while(f < r){
		p = q[++f];
		// ���Һ��Ӳ�Ϊ�գ��ֱ���� 
		if(p->lchild){
			q[++r] = p->lchild;
		}
		if(p->rchild){
			q[++r] = p->rchild;
		}
		// f == L����ʾ��������ǰ�� �� ���� ��� 
		if(f == Latest){
			// �߶� + 1 
			depth++;
			// L ָ����һ�� �� ���� ��� 
			Latest = r;
		}
	}
	return depth; 
}

int main(){
	
	tree t;
	buildtree(t);
	printf("���ߣ�%d", dept(t));
	
	return 0;
} 





