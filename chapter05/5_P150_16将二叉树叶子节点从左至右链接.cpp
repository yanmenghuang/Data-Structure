#include<stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

// ������ 
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
		
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

void disp(tree t){
	if(t){
		disp(t->lchild);
		printf("%c	", t->data);
		disp(t->rchild);
	}
} 

// ȫ�ֱ��� 
// �� ͷ�ڵ� �����ڴ���� 
tree head = (treenode *) malloc(sizeof(treenode)); 
// ǰ�����  ��ʼֵ �ÿ� 
tree pre = NULL;

// ����ݹ���� 
tree InOrder(tree t){
	// "��ǰ���" ��Ϊ��  ��Ϊ�գ������κβ��� 
	if(t){
		// �ݹ���� ������ 
		InOrder(t->lchild);
		
		// �ҵ� Ҷ�ӽ�㣨���Һ��Ӿ�Ϊ�գ� 
		if(t->lchild == NULL && t->rchild == NULL){
			// ����� ��һ��Ҷ�ӽ�� 
			if(pre == NULL){
				head = t;
				pre = t;
			}
			// ���� ��һ��Ҷ�ӽ��  
			else{
				// ��ǰ��������ָ�� ָ�� ��ǰҶ�ӽ�� 
				pre->rchild = t;
				// ����ǰ����� ��֤�����ٴ�����Ҷ�ӽ��ʱ��֪��ǰ�� ���ܹ��������� 
				pre = t;
			}
		}
		
		// �ݹ���� ������ 
		InOrder(t->rchild);
		
		// �� ���һ��Ҷ�ӽ�� ����ָ�� ��Ϊ�� 
		pre->rchild = NULL; 
	}
} 

int main(){
	
	tree t;
	// ABD##E##CF##G##
	buildtree(t);
	disp(t);
	printf("\n");
	
	InOrder(t);
	while(head){
		printf("%c	", head->data);
		head = head->rchild;
	}
	
	return 0;
}
