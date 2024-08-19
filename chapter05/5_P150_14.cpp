
#include<stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

typedef struct{
	tree data[10];
	int level[10];
	int f, r;
}Qu;

buildtree(tree &t){
	char ch;
	ch = getchar();
	
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *) malloc(sizeof(treenode));
		// ��ֵ 
		t->data = ch;
		// ���Һ������ÿ� 
		t->lchild = NULL;
		t->rchild = NULL;
		
		// ���Һ��ӵݹ鸳ֵ 
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// ��α��� 
int width(tree t){
	// ���� 
	Qu Q;
	// ���ӽڵ��ָ�� 
	treenode* p; 
	// ������ӽڵ�Ĳ�� 
	int k;
	// ͷβָ���ʼ�� 
	Q.f = -1;
	Q.r = -1;
	// βָ����ƣ����ڵ���� 
	Q.r++;
	Q.data[Q.r] = t;
	// ���ڵ���Ϊ 1 
	Q.level[Q.r] = 1;
	
	while(Q.f < Q.r){
		// ͷָ����Ƴ��� 
		Q.f++;
		// ������ӽڵ�
		p = Q.data[Q.f];
		// ������ӽڵ��� 
		k = Q.level[Q.f]; 
		
		// ���ӷǿգ����ӽ���
		if(p->lchild != NULL){
			// βָ����� ������� 
			Q.r++;
			// ���ӽ������ 
			Q.data[Q.r] = p->lchild;
			// ������еĽڵ�Ĳ�� = ���ӽڵ�Ĳ�� + 1 
			Q.level[Q.r] = k + 1;
		}
		// �Һ��ӷǿգ��Һ��ӽ��� 
		if(p->rchild != NULL){
			Q.r++;
			Q.data[Q.r] = p->rchild;
			// ������еĽڵ�Ĳ�� = ���ӽڵ�Ĳ�� + 1 
			Q.level[Q.r] = k + 1; 
		}
	}
	
	int max = 0, i = 0, n;
	// �� ��һ�� ��ʼ 
	k = 1;
	while(i <= Q.r){
		// һ��ʼĬ��ÿ��Ĭ��0��
		n = 0;
		while(i <= Q.r && Q.level[i] == k){
			// ÿ���������
			n++;
			// �������±����
			i++; 
		} 
		// ��һ��Ĳ�� 
		k = Q.level[i];
		
		if(n > max){
			max = n;
		}
	}
	
	return max;
	
}

int main(){
	
	tree t;
	// ABD##E##CF##G##
	buildtree(t);
	
	int w = width(t); 
	printf("%d	", w);
	/*
				A
			B		C
		  D   E   F    G
	*/ 
	
	return 0;
}
