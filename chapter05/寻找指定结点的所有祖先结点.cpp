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

// �ǵݹ�������
void grand(tree t, char x){
	// ջ ջ��ջ��ָ��top�ĳ�ʼ��ָ�� -1
	Stack s[10];
	int top = -1;
	treenode* p = t;
	
	// ��ǰ��㲻Ϊ�� ���� ջ�ǿ� 
	while(p != NULL || top != -1){
		while(p != NULL && p->data != x){
			// �Ӹ��ڵ������������ѹ��ջ�� ���ҽڵ��ֵ��Ϊ x 
			s[++top].t = p;
			
			// ��ʾ ջ����� ������ �ѷ���  
			s[top].tag = 0; 
			p = p->lchild;
		}
		
		// ����ҵ� ֵΪ x �Ľڵ㣬��ջ�нڵ����
		if(p != NULL && p->data == x){
			printf("���е����Ƚ��Ϊ��\n");
				for(int i = 0; i <= top; i++){
					printf("%c	", s[i].t->data);
			}
		}
		
		// �жϵ�ǰջ���Ľ��� tagֵ��
		// tag == 1����ʾ ջ����� �����Һ��Ӿ������ʣ�������ջ
		// top != 0 ����ʾջ��Ϊ�� 
		while(top != -1 && s[top].tag == 1){
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
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}	
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HGJ##K##IL##M## 
	buildtree(t);
	disp(t);
	printf("\n");
	grand(t, 'B');
	
	/*
					F
				E		 H
			 C        G     I
		  A    D    J   K  L M
		   B
	*/
	
	return 0;
} 
