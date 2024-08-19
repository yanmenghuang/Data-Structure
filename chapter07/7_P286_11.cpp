#include<stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct treenode{
	char data;
	int count;
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
		t->count = 0;
		t->lchild = NULL;
		t->rchild = NULL;
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// ���� ÿһ����� ��������� ��������㱾�� 
int num(tree &t){
	if(t){
		if(t->lchild == NULL && t->rchild == NULL){
			// �� ��ǰ����count ��ֵ 
			t->count = 1;
			return t->count;
		}
		else{
			// �ݹ���� ������ 
			int b1 = num(t->lchild);
			// �ݹ���� ������ 
			int b2 = num(t->rchild);
			// �� ��ǰ����count ��ֵ 
			t->count = b1 + b2 + 1; 
			return t->count;
		}
	}
}

treenode *min_k(tree t, int k){
	// ����� Kֵ �Ƿ� 
	if(k < 1 || k > t->count){
		return NULL;
	}
	// ������ Ϊ�� 
	if(t->lchild == NULL){
		if(k == 1){
			return t;
		}
		else{
			min_k(t->rchild, k-1);
		}
	}
	// ������ ��Ϊ�� 
	else{
		// ������������ = K-1���� K С�����Ǹ��ڵ� 
		if(t->lchild->count == k-1){
			return t;
		}
		// ������������ > K-1������������ �� K С 
		if(t->lchild->count > k-1){
			return min_k(t->lchild, k);
		}
		// ������������ < K-1������������ �� (K - ������������) С 
		if(t->lchild->count < k-1){
			return min_k(t->rchild, k - (t->lchild->count + 1));
		}
	}
}

// ������� 
void disp(tree t){
	if(t->lchild != NULL){
		disp(t->lchild);
	}
	
	printf("data = %c, count = %d	", t->data, t->count);
	
	if(t->rchild != NULL){
		disp(t->rchild);
	}
}


int main(){
	
	tree t;
	// �������У�FECA#B##D###HG##I##
	buildtree(t);
	
	num(t);
	disp(t);
	
	treenode *p = min_k(t, 7);
	printf("%c	", p->data); 
	
	// printf("�������%d	", t->count);
	
	// printf("test");
	
	/*
					F
				E		H
			 C        G    I
		  A    D
		    B
	*/
	
	return 0;
} 
