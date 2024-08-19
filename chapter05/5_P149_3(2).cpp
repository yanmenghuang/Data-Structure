#include<stdio.h>
#include <stdlib.h>
using namespace std;

// ǰ���С�����ǵݹ��㷨

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

// �ǵݹ�������� 
void PreOrder(tree t){
	// ջ��ջ��ָ��top�ĳ�ʼ��ֵ ��Ϊ -1 
	Stack s[10]; 
	int top = -1;
	treenode* p = t;
	// ��ǰ��� ��ΪNULL �� ջ�ǿ� 
	while(p != NULL || top != -1){
		while(p != NULL){
			// ���ʸ���� 
			visit(p->data);
			// ѹ��ջ�� 
			s[++top].t = p;
			// ���������� 
			p = p->lchild;
		}
		// ջ�ǿ� 
		if(top != -1){
			// ջ��Ԫ�أ�������ǰ����㡱����ջ 
			p = s[top].t;
			top--;
			// ���������� 
			p = p->rchild;
		}
	}
}

// �ǵݹ�������� 
void InOrder(tree t){
	// ջ��ջ��ָ��top�ĳ�ʼ��ֵ ��Ϊ -1 
	Stack s[10]; 
	int top = -1;
	treenode* p = t;
	// ��ǰ��� ��ΪNULL �� ջ�ǿ� 
	while(p != NULL || top != -1){
		while(p != NULL){
			// ѹ��ջ�� 
			s[++top].t = p;
			// ���������� 
			p = p->lchild;
		}
		// ջ�ǿ� 
		if(top != -1){
			// ջ��Ԫ�أ�������ǰ����㡱����ջ 
			p = s[top].t;
			top--;
			// ���ʸ���� 
			visit(p->data);
			// ���������� 
			p = p->rchild;
		}
	}
}

// �ǵݹ�������
void PostOrder(tree t){
	treenode* p = t;
	// ջ ջ��ջ��ָ��top�ĳ�ʼ��ֵ ��Ϊ -1 
	Stack s[10]; 
	int top = -1;
	
	// ��ǰ��㲻Ϊ�� ���� ջ�ǿ� 
	while(p != NULL || top != -1){
		while(p != NULL){
			// �Ӹ��ڵ������������ѹ��ջ�� ���ҽڵ��ֵ��Ϊ x 
			s[++top].t = p;
			// ��ʾ ջ����� ������ �ѷ���  
			s[top].tag = 0; 
			p = p->lchild;
		} // whileѭ��������p ָ�� NULL 
		
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
			// ��� ָ�� ջ�������Һ���  
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
	// ǰ�����У�ABD##E##CF##G##
	buildtree(t);
	disp(t); // ǰ�� 
	printf("\n");
	printf("ǰ�������");
	PreOrder(t);
	printf("\n");
	printf("���������");
	InOrder(t);
	printf("\n");
	printf("���������");
	PostOrder(t);

	return 0;
} 
