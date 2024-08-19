#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

/*
		1��ΪʲôҪ��������������
		���ھ�����Ҫ��������ҽ�� �ڱ����������������е� ǰ���ͺ����Ϣ��
		����������������Ч�ʸߣ�����Ҫ��ջ��
		
		2����β���ǰ���ͺ����Ϣ�� 
		���������Զ���������Ϊ�洢�ṹʱ��ֻ���ҵ��������Һ�����Ϣ��
		������ֱ�ӵõ������һ�����е�ǰ���ͺ����Ϣ��ǰ��ͺ����Ϣֻ���ڱ����Ķ�̬�����в��ܵõ��� 
*/ 



typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
	// ltag = 0��lchildָ��ָ���������  ltag = 1��lchildָ��ָ�����ǰ�� 
	// rtag = 0��rchildָ��ָ������Һ���  rtag = 1��rchildָ��ָ����ĺ�� 
	int ltag, rtag;
}treenode, *tree; 

void buildtree(tree &t);
void InOrderThreading(tree &thrt, tree t);
void InThreading(tree p);
void InOrderTraverse(tree thrt); 
void InOrderTraverseReverse(tree thrt);

// �������н��������� 
void buildtree(tree &t){
	char ch;
	ch = getchar();
	
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		t->ltag = 0;
		t->rtag = 0;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}


treenode* pre; 

// ���������� 
void InOrderThreading(tree &thrt, tree t){
	// ��ͷ��� (Ϊͷ�ڵ�ָ�����洢�ռ�)
	thrt = (treenode*) malloc(sizeof(treenode));
	thrt->ltag = 0;
	thrt->rtag = 1;
	// ��ָ�� ��ָ 
	thrt->rchild = thrt;
	if(t == NULL){
		// ������t Ϊ�գ�ͷ�ڵ����ָ�� ��ָ 
		thrt->lchild = thrt;
	} 
	else{
		thrt->lchild = t;
		pre = thrt;
		// ������� ���� ���������� 
		InThreading(t);
		// ���һ����� ������
		pre->rchild = thrt;
		pre->rtag = 1;
		thrt->rchild = pre; 
	}
}

// ������� ��������������
void InThreading(tree p){
	// ��� �ǿ� 
	if(p){
		// �������� ����������ĵ�һ����� 
		InThreading(p->lchild); // ������������ 
		
		if(p->lchild == NULL){ // ��ǰ��� ���� Ϊ�� 
			p->ltag = 1;
			// �� ����ָ�� ָ�� �������ʱ�� ǰ����� 
			p->lchild = pre;
		} 
		
		if(pre->rchild == NULL){ // ǰ����� �Һ��� Ϊ�� 
			pre->rtag = 1;
			// �� ǰ�������Һ���ָ�� ָ�� ��ǰ��� 
			pre->rchild = p;  
		}
		// ����ǰ����� 
		pre = p;
		
		InThreading(p->rchild); // ������������ 
	}
} 


// p->rtag = 1����ָ��������,����Ϊ �Һ��� 
// p->rtag = 0���ý�����Һ��ӣ�������Ϊ �����������½��
// ���������������ı���
void InOrderTraverse(tree thrt){
	// p ָ��ԭ�������ĸ���� 
	treenode* p = thrt->lchild;
	while(p != thrt){
		// ��һ�� while ѭ�����ҵ� ��������ĵ�һ����� 
		// ����ÿһ�� while ѭ�����ҵ� �����������½�� 
		while(p->ltag == 0){
			p = p->lchild;
		}
		// ���ʵ�һ����� 
		printf("%c	", p->data);
		// �ұ�־Ϊ 1����ֱ�ӵõ� ��̽�� 
		while(p->rtag == 1 && p->rchild != thrt){
			p = p->rchild;
			printf("%c	", p->data);
		}
		// whileѭ��������p->rtag = 0;
		// �ұ�־Ϊ 0���� ���Ϊ �����������½ǽ�� 
		// �ұ�־Ϊ 0���� pָ�� ָ�� p���Һ���  
		p = p->rchild;
	} 
} 

// p->ltag = 1����ָ��������,��ǰ��Ϊ ���� 
// p->ltag = 0���ý�������ӣ�����ǰ��Ϊ �����������½��
// ��������������������� 
void InOrderTraverseReverse(tree thrt){
	treenode* p = thrt->lchild;
	while(p != thrt){
		// ��һ�� while ѭ��������������������һ����� 
		// ����ÿһ�� while ѭ�����ҵ������������½�� 
		while(p->rtag == 0){
			p = p->rchild;
		}
		// �������һ����� 
		printf("%c	", p->data);
		while(p->ltag == 1 && p->lchild != thrt){
			p = p->lchild;
			printf("%c	", p->data);
		}
		p = p->lchild;
	}
	printf("\n");
}

int main(){
	
	tree t;
	tree thrt;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	// ���������� 
	InOrderThreading(thrt, t);
	
	// ���������������ı�����A B C D E F G H I  
	InOrderTraverse(thrt); 
	printf("\n"); 
	// �����������������������I H G F E D C B A 
	InOrderTraverseReverse(thrt);
	/*
				F
			E		H
		 C        G    I
	  A    D
	    B
	*/
	return 0;
}
