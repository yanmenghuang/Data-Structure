#include<stdio.h>
#include <stdlib.h>
using namespace std;

/*
		ƽ������������������������ �߶Ȳ�ľ���ֵ������ 1 
		ƽ�����ӣ������� �� ������ �ĸ߶Ȳƽ�����ӵ�ֵֻ���� -1��0��1 
*/ 

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

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

// ������� ���ж��Ƿ��� ƽ�������  
void isAVL(tree t,int &height, int &balance){
	// ���������߶�  
	int h1 = 0, h2 = 0;
	// ��������ƽ������ 
	int b1 = 0, b2 = 0;
	
	// �������߶�Ϊ 0 ƽ������Ϊ 1
	if(t == NULL){
		height = 0;
		balance = 1;
	} 
	// ֻ��һ�����ڵ㣺�߶�Ϊ 1 ƽ������Ϊ 1 
	else if(t->lchild == NULL && t->rchild == NULL){
		height = 1;
		balance = 1; 
	}
	else{
		// �ݹ����������
		isAVL(t->lchild, h1, b1);
		// �ݹ����������
		isAVL(t->rchild, h2, b2);
		// ��ǰ�������� = ���������ϴ��� + 1 
		height = (h1 > h2 ? h1 :h2) + 1;
		
		// ���������߶Ȳ�ľ���ֵ С�ڵ��� 1 
		if(abs(h1 - h2) <= 1){
			// ������������ƽ�������ʱ����ƽ������� 
			balance = b1 && b2;
		}
		else{
			balance = 0;
		}
	}
}

int main(){
	
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	
	int height, balance;
	isAVL(t, height, balance);
	
	printf("height = %d, balance = %d", height, balance);
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
	return 0;
}

