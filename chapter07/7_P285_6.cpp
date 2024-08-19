#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

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
		t = (treenode*) malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild); 
		buildtree(t->rchild);

	}
}

// ��ʼ��ǰ�� 
int pre = -3555;

int isok(tree t){
	// �ж��� �Ƿ�Ϊ��    ���� Ҳ�� ���������� 
	if(t == NULL){
		return 1;
	}
	
	else{
		// �ݹ��������� �Ƿ��� ����������
		int b1 = isok(t->lchild);
		// �ж���������ֵ �� ��ǰ��� �� ǰ�����ֵ �ıȽ�
		// ������ ���� ����������  ����   ��ǰ��� < ǰ�����ֵ
		if(b1 == 0 || ((t->data) - '0') <= pre){
			// ���������Ƕ�����������ֱ�ӷ��� 
			return 0;
		} 
		// ����ǰ�����
		pre = (t->data) - '0'; 
		// �ݹ���������֮ǰ�������������Ƕ��������� 
		// �ݹ��������� �Ƿ��� ����������
		return isok(t->rchild);
	}
} 

int main(){
	
	tree t;
	// FECA#B##D###HG##I##
	/*
						F
					E		 H
				C         G    I
			  A    D 
			    B 
	*/
	buildtree(t);
	
	int ok = isok(t);
	
	if(ok){
		printf("yes");
	}
	else{
		printf("no");
	}
	
	return 0;
}
