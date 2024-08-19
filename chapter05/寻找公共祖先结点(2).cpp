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
	++s.top;
	s.data[s.top] = x;
}

void Pop(Stack &s){
	if(isEmpty(s)){
		printf("ջ�գ�����");
		return;
	}
	s.top--;
}

// ����ǵݹ��ҹ������Ƚ�㣺�ٶ����������� X �� Y ��ǰ�� 
treenode* Ancestor(tree t, char X, char Y){
	Stack s1, s2;
	InitStack(s1);
	InitStack(s2); 
	// ������������ָ��
	treenode *p = t;
	// ��ѭ������������ǰ�����Ľڵ㲻��Ϊ�� ���� ջ1��ջ��ָ�� != -1(ջ��Ϊ��)
	while(p != NULL || !isEmpty(s1)){
		// ��������ѹ��ջ
		while(p != NULL){
			Push(s1, p);
			s1.data[s1.top]->tag = 0;
			p = p->lchild;   // ����ָ������ 
		}
		// ջ1��Ϊ�� ���� tag = 1
		while(s1.top != -1 && s1.data[s1.top]->tag == 1){  
		
			// ���ջ���Ľڵ����p���͸��Ƶ�ջ2�У�ջ2��ջ��ָ�� ��ʱ��ֵ top1��ֵ
			if(s1.data[s1.top]->value == X){
				for(int i = 0; i < s1.top; i++){
					s2.data[i] = s1.data[i];
				}
				s2.top = s1.top;
			}
			// ���ջ���Ľڵ����q ��ջ1 ����ƥ�� 
			// Ҫ��������������ȣ��� ջ�����½���ƥ�� 
			if(s1.data[s1.top]->value == Y){
				for(int i = s1.top - 1; i > -1; i--){
					for(int j = s2.top; j > -1; j--){
						// ƥ��ɹ���ֱ�ӷ��� 
						if(s2.data[j]->value == s1.data[i]->value){
							return s1.data[i];
						}
					}
				}
			}
			// ��ջ
			Pop(s1); 
		}
		
		// ջ����ʱ����ջ����tag = 1�����ҵ�ǰ�Ľڵ�ָ��ýڵ���Һ��� 
		if(!isEmpty(s1)){
			s1.data[s1.top]->tag = 1;
			p = s1.data[s1.top]->rchild;
		}
	}
	return NULL; // û�й������ȣ�����NULL 
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

	tree ancestor = Ancestor(t, 'B', 'A');
	printf("%c	", ancestor->value);
	
	/*
				F
			E		 H
		 C        G     I
	  A    D    J   K  L M
	   B
	*/ 
	
	return 0;
} 
