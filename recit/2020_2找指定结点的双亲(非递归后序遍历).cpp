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

// �ǵݹ�������
void FindParent(tree t, char x){
	// ջ ջ��ջ��ָ��top�ĳ�ʼ��ָ�� 0
	Stack s[10];
	int top = -1;
	
	// ��ǰ��㲻Ϊ�� ���� ջ�ǿ� 
	while(t != NULL || top != -1){
		while(t != NULL && t->data != x){
			// �Ӹ��ڵ������������ѹ��ջ�� ���ҽڵ��ֵ��Ϊ x 
			s[++top].t = t;
			
			// ��ʾ ջ����� ������ �ѷ���  
			s[top].tag = 0; 
			t = t->lchild;
		}
		
		// ����ҵ� ֵΪ x �Ľڵ㣬��ջ�нڵ����
		if(t != NULL && t->data == x){
			printf("%c	", s[top].t->data);
			/*
			printf("���е����Ƚ��Ϊ��\n");
			for(int i = 1; i <= top; i++){
				printf("%c	", s[i].t->data);
			}
			*/
		}
		
		// �жϵ�ǰջ���Ľ��� tagֵ��
		// tag == 1����ʾ ջ����� �����Һ��Ӿ������ʣ�������ջ
		// top != -1 ����ʾջ��Ϊ�� 
		while(top != -1 && s[top].tag == 1){
			// ��ջ 
			top--;
		}
		
		// ��ǰջ����Ϊ -1�����ǿգ���
		if(top != -1){
			// ��ջ����tag��ֵΪ 1
			s[top].tag = 1;
			// ���ָ��ý����Һ���  
			t = s[top].t->rchild;
		}
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
	tree t;
	buildtree(t);
	// �������У�FECA#B##D###HG##I##
	disp(t);
	printf("\n");
	FindParent(t, 'B');
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
	return 0;
} 
