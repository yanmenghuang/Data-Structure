#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 20

// �ǵݹ� ������� �㷨 

// ���ṹ��
typedef struct treenode{
	char value;
	struct treenode *lchild, *rchild;
	// �ڵ�����Һ��ӷ��ʱ��� 
	// tag = 0�������Ѿ����ʹ���tag = 1���Һ��ӷ��ʹ� 
	int tag;
}treenode, *tree;

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
		t->value = ch;
		// �� ���Һ��� ��Ϊ ��
		t->lchild = NULL;
		t->rchild = NULL;
		
		// �ݹ�� ���Һ��Ӹ�ֵ
		buildtree(t->lchild);
		buildtree(t->rchild); 
	}
}

// �ڵ�ջ �Ľṹ�� 
typedef struct{
	// ���Ľڵ�
	treenode* data[Max];
	int top;
}Stack;

void InitStack(Stack &s){
	s.top = -1;
}

bool isEmpty(Stack s){
	if(s.top == -1){
		return true;
	}
	return false;
}

bool isFull(Stack s){
	if(s.top == Max -1){
		return true;
	}
	return false;
}

void Push(Stack &s, treenode* x){
	if(isFull(s)){
		printf("ջ��������");
		return;
	}
	s.data[++s.top] = x;
}

void Pop(Stack &s){
	if(isEmpty(s)){
		printf("ջ�գ�����");
		return;
	}
	s.top--;
}

// �ǵݹ�������
void grand(tree t, char x){
	// ջ ջ��ջ��ָ��top�ĳ�ʼ��ָ�� 0
	Stack s;
	InitStack(s);
	treenode* p = t;

	// ��ǰ��㲻Ϊ�� ���� ջ�ǿ� 
	while(p != NULL || !isEmpty(s)){
		while(p != NULL && p->value != x){
			// �Ӹ��ڵ������������ѹ��ջ�� ���ҽڵ��ֵ��Ϊ x 
			Push(s, p);
			// ��ʾ ջ����� ������ �ѷ��� 
			s.data[s.top]->tag = 0;
			p = p->lchild;
		}
		
		// ����ҵ� ֵΪ x �Ľڵ㣬��ջ�нڵ����
		if(p != NULL && p->value == x){
			printf("���е����Ƚ��Ϊ��\n");
			for(int i = 0; i <= s.top; i++){
				printf("%c	", s.data[i]->value);
			}
		}
		
		// �жϵ�ǰջ���Ľ��� tagֵ��
		// tag == 1����ʾ ջ����� �����Һ��Ӿ������ʣ�������ջ
		// top != 0 ����ʾջ��Ϊ�� 
		while(!isEmpty(s) && s.data[s.top]->tag == 1){
			// ��ջ����ջ��㲻��Ҫ���� 
			Pop(s);
		}
		
		// ��ǰջ����Ϊ 0�����ǿգ���
		if(!isEmpty(s)){
			// ��ջ����tag��ֵΪ 1
			s.data[s.top]->tag = 1;
			// ���ָ��ý����Һ���
			p = s.data[s.top]->rchild;  	
		}
	}
} 

void disp(tree t){
	if(t){
		disp(t->lchild);
		disp(t->rchild);
		printf("%c	", t->value);
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
