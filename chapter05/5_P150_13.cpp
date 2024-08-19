#include<stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

// ���ṹ��

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree; 

typedef struct{
	// ���Ľڵ�
	treenode *t;
	//  ���Һ��ӷ��ʱ��� tag = 0�����ӷ��ʹ���tag = 1���Һ��ӷ��ʹ�
	int tag; 
}Stack;

void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		// ���ڵ����ռ� 
		t = (treenode *)malloc(sizeof(treenode));
		// �Խڵ㸳ֵ 
		t->data = ch;
		// ���Һ����ÿ� 
		t->lchild = NULL;
		t->rchild = NULL;
		// �ݹ鸳ֵ���Һ��� 
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

tree Ancestor(tree t, treenode *p, treenode *q){
	// ��������ջ
	Stack S1[10], S2[10]; // �ṹ������
	// ջ��ָ���ʼ��
	int top1 = 0,top2;
	// ������������ָ��
	treenode *tt = t;
	// ��ѭ������������ǰ�����Ľڵ㲻��Ϊ�� ���� ջ1��ջ��ָ�� > 0(ջ��Ϊ��)
	while(tt != NULL || top1 >0){
		
		// ��������ѹ��ջ
		while(tt != NULL){
			S1[++top1].t = tt; // ѹ��ջ�� 
			S1[top1].tag = 0;  //��ʾ���ӷ��ʹ� 
			tt = tt->lchild;   // ����ָ������ 
		}
		
		while(top1 != 0 && S1[top1].tag == 1){  // ջ1��Ϊ�� ����tag = 1
		
			// ���ջ���Ľڵ����p���͸��Ƶ�ջ2�У�ջ2��ջ��ָ�� ��ʱ��ֵ top1��ֵ
			if(S1[top1].t == p){
				for(int i =1; i < top1; i++){
					S2[i] = S1[i];
				}
				top2 = top1;
			}
			// ���ջ���Ľڵ����q ��ջ1 ����ƥ�� 
			if(S1[top1].t == q){
				for(int i = top1 - 1; i > 0; i--){
					for(int j = top2; j > 0; j--){
						// ƥ�䣬ֱ�ӷ��� 
						if(S2[j].t == S1[i].t){
							return S1[i].t;
						}
					}
				}
			}
			
			top1--; // ��ջ
		}
		
		// ջ����ʱ����ջ����tag = 1�����ҵ�ǰ�Ľڵ�ָ��ýڵ���Һ��� 
		if(top1 != 0){
			S1[top1].tag = 1;
			tt = S1[top1].t->rchild;
		}
	}
	
	return NULL; // û�й������ȣ�����NULL 
	
} 

int main(){
	
	tree t;
	// �������У�FECA#B##D###HGJ##K##IL##M##
	buildtree(t);
	// �Զ��� p q�ڵ��ָ�� 
	treenode *p = t->rchild->lchild, *q = t->rchild->rchild; 
	tree ancestor = Ancestor(t, p, q);
	printf("%c	", ancestor->data);
	
		/*
					F
				E		 H
			 C        G     I
		  A    D    J   K  L M
		   B
	*/ 
	
	return 0;
}





