#include<stdio.h>
#include <stdlib.h>
using namespace std;

// ����ǵݹ��㷨 

typedef struct TreeNode{
	char data;
	// ��־�򣺱�ʾ���Һ����Ƿ񱻷��ʹ� 
	int tag; 
	struct TreeNode *lchild, *rchild;
}TreeNode, *Tree;

// ͨ�� �������� ������ ������ 
void buildTree(Tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (TreeNode *) malloc(sizeof(TreeNode));
		t->data = ch;
		// ��ʼʱ����־����Ϊ 0 
		t->tag = 0;
		t->lchild = NULL;
		t->rchild = NULL;
		// �ݹ�ȥ��ֵ�ýڵ�����Һ��� 
		buildTree(t->lchild);
		buildTree(t->rchild);

	}
}

void PostOrder(Tree t){
	struct TreeNode *stack[100];
	int top = -1;
	TreeNode *p = t;
	// ���������ջ��� 
	TreeNode *q;
	
	// p ��㲻Ϊ�� ���� ջ�ǿ� 
	while(p != NULL || top != -1){
		if(p != NULL){
			top++;
			stack[top] = p;
			p = p->lchild;
		} 
		// pΪ�� 
		else{
			// �� p ָ��ջ��Ԫ�� 
			p = stack[top];
			
			// p(ջ��Ԫ��) �Һ��ӷǿգ������Һ���û�б����ʹ� 
			if(p->rchild != NULL && p->rchild->tag == 0){
				p = p->rchild;
			}
			// p(ջ��Ԫ��) �Һ��ӷǿգ��� �Һ��ӱ����ʹ� 
			else{
				// ��ջ�����ջ��Ԫ�� 
				p = stack[top];
				top--;
				printf("%c	", p->data);
				// p ��ǰָ��Ľ��� tagֵ ��Ϊ 1 
				p->tag = 1;
				// p ָ��� 
				p = NULL;
			}
		}
	} 
}

void disp(Tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}	
}

int main(){
	
	Tree t;
	// ǰ�����У�ABD##E##CF##G##
	buildTree(t);
	
	disp(t);
	
	printf("\n");

	PostOrder(t);
	
	return 0;
	
	return 0;
}



