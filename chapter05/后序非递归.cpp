#include<stdio.h>
#include <stdlib.h>
using namespace std;

// �ǵݹ� ������� �㷨 

// ���ṹ��
typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

// �ڵ�ջ �Ľṹ�� 
typedef struct{
	// ���Ľڵ�
	treenode *t;
	// �ڵ�����Һ��ӷ��ʱ��� 
	// tag = 0�������Ѿ����ʹ���tag = 1���Һ��ӷ��ʹ� 
	int tag;
}Stack;

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

void visit(char c){
	printf("%c	", c); 
}

// �ǵݹ�������
void PostOrder(tree t){
	// ջ ջ��ջ��ָ��top�ĳ�ʼ��ֵ ��Ϊ -1 
	Stack s[10]; 
	int top = -1;
	
	treenode* p = t;
	
	// ��ǰ��㲻Ϊ�� ���� ջ�ǿ� 
	while(p != NULL || top != -1){
		while(p != NULL){
			// �Ӹ��ڵ������������ѹ��ջ�� ���ҽڵ��ֵ��Ϊ x 
			s[++top].t = p;
			// ��ʾ ջ����� ������ �ѷ���  
			s[top].tag = 0; 
			p = p->lchild;
		}
		
		// �жϵ�ǰջ���Ľ��� tagֵ��
		// tag == 1����ʾ ջ����� �����Һ��Ӿ������ʣ�������ջ
		// top != -1 ����ʾջ��Ϊ�� 
		while(top != -1 && s[top].tag == 1){
			// ջ����� �����Һ��Ӿ������ʣ����ջ��Ԫ��
			visit(s[top].t->data); 
			top--;
		}
		
		// ��ǰջ����Ϊ -1�����ǿգ���
		if(top != -1){
			// ��ջ����tag��ֵΪ 1
			s[top].tag = 1;
			// ���ָ��ý����Һ���  
			p = s[top].t->rchild;
		}
	}
}
void disp(tree t){
	if(t){
		disp(t->lchild);
		disp(t->rchild);
		printf("%c	", t->data);
	}	
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HGJ##K##IL##M## 
	buildtree(t);
	disp(t);
	printf("\n");
	
	PostOrder(t);
	
	/*
					F
				E		 H
			 C        G     I
		  A    D    J   K  L M
		   B
	*/
	
	return 0;
} 
