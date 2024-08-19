#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

int pos = 5;

tree build(char a[], char b[], int s, int e){
	if(s <= e){
		treenode *root = (treenode *)malloc(sizeof(treenode));
		root->data = a[pos];
		int i;
		for(i = s; i <= e; i++){
			// ע�⣺ÿһ�εݹ���ã��� b�������ҵ�����ǰ�����ڵ� 
			// i ͣ����λ�ã����Ǹ��ڵ��λ�� 
			if(b[i] == root->data){
				break;
			}
		}
		pos--;
		/*
			�Ӻ���ǰ���ȸ����������������� 
		*/ 
		// ������������ֻ��Ҫ������������������ȥ�� 
		root->rchild = build(a, b, i+1, e);
		// ������������ֻ��Ҫ������������������ȥ�� 
		root->lchild = build(a, b, s, i-1);
		
		return root;
	}
	
	// �ݹ�������� ���� �����Һ��ӵĸ��ڵ㣩 
	return NULL;
}

void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}
} 

int main(){
	// �������� 
	// DEBFCA
	char a[] = {'D', 'E', 'B', 'F', 'C', 'A'}; 
	// �������� 
	char b[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	
	tree root = build(a, b, 0, 5);
	
	printf("�������У�");
	disp(root); 
	
	
	 
	return 0;
}

