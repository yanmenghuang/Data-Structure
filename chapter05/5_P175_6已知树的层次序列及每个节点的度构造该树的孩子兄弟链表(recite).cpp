#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 20

typedef struct treenode{
	char data;
	struct treenode *child, *brother; 
}treenode, *tree;

void create(tree &t, char e[], int degree[], int n){
	// ��������� ���� 
	tree* point = new tree[10];
	// tree *point = (tree*) malloc(sizeof(tree) * Max);
	for(int i = 0; i < n; i++){
		// ����ʼ�� 
		point[i] = (treenode *) malloc(sizeof(treenode));
		point[i]->data = e[i];
		point[i]->child = NULL;
		point[i]->brother = NULL;
	}
	
	// ���ӽ����� 
	int k = 0; 
	// ���ո��Ľ��˳����ʽ��
	for(int i = 0; i < n; i++){
		int d = degree[i];
		// ����ж� ˵���к���
		if(d){
			// ����һ������ ��Ϊ�Լ������ӽ�� 
			k++;
			point[i]->child = point[k];
			// d ��ǰ���Ķ� 
			// ʣ��ĺ��� ÿ���������Ϊǰһ�������ֵܽ��
			for(int j = 2; j <= d; j++){
				k++;
				point[k-1]->brother = point[k];
			} 
		} 
	}
	// �����ͷ Ϊ ��һ����� 
	t = point[0]; 
	// ��̬������ڴ�����ͷ� ��ֹ�ڴ�й¶
	delete [] point; 
}

void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->child);
		disp(t->brother);
	}
} 

int main(){
	
	tree t;
	// ��α������� 
	char e[8] = "ABCDEFG";
	// ÿ�����ȵ����� 
	int degree[8] = {3, 2, 1, 0, 0, 0}; 
	/*
					A
				B		C	D
			  E   F     G 
	*/
	create(t, e, degree, 7);
	
	disp(t);
	
	return 0;
}
