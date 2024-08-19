#include<stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;


typedef struct treenode{
	int weight;
	struct treenode *lchild, *rchild;
}treenode, *tree;

void buildtree(tree &t){
	char ch;
	ch = getchar();
	
	if(ch =='#'){
		t = NULL;
	}
	else{
		// ����ռ�
		t = (treenode *) malloc(sizeof(treenode));
		// ��ֵ
		t->weight = ch;
		// ��ʼ��
		t->lchild = NULL;
		t->rchild = NULL;
		// �ݹ鸳ֵ 
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

int wplpre(tree t, int deep){
	// ��̬�������洢���������ĩβ���� 
	static int wpl = 0;
	if(t == NULL){
		return wpl;
	}
	// Ҷ�ӽڵ㣬����Ȩֵ 
	if(t->lchild == NULL && t->rchild == NULL){
		wpl += (deep * (t->weight - '0'));
	}
	// �ݹ��������������deep + 1 
	wplpre(t->lchild, deep+1);
	wplpre(t->rchild, deep+1);

	return wpl;
}

int main(){
	tree t;
	// 124##5##36##7## 
	buildtree(t);
	int wpl = wplpre(t, 0);
	printf("%d	", wpl);
	
	/*
				1
			2		3
		  4   5   6   7
	*/
	
	return 0;
} 



