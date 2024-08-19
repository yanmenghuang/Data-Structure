#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

typedef struct BstNode{
	dataType data;
	struct BstNode *lchild;
	struct BstNode *rchild;
}BSTNode, *BSTtree;

// & ������ 
void insertBST(BSTtree &bt, dataType key){
	if(bt == NULL){
		bt = (BSTtree) malloc(sizeof(BSTNode));
		bt->data = key;
		bt->lchild = NULL;
		bt->rchild = NULL;
	}
	else if(bt->data > key){
		insertBST(bt->lchild, key);
	}
	else if(bt->data < key){
		insertBST(bt->rchild, key);
	}
}

void create_BST(BSTtree &T, int a[], int n){
	T = NULL;
	for(int i = 0; i < n; i++){
		insertBST(T, a[i]);
	}
}

// �ݹ���� 
BSTNode* searchBST(BSTtree T, dataType key){
	if(T == NULL){
		return NULL;
	}
	else if(T->data == key){
		return T;
	}
	else if(T->data > key){
		return searchBST(T->lchild, key);
	}
	else{
		return searchBST(T->rchild, key);
	}
}

BSTNode* searchBST1(BSTtree T, dataType key){
	while(T != NULL && T->data != key){
		if(T->data > key){
			T = T->lchild;
		}
		else{
			T = T->rchild;
		}
	}
	return T;
}

void inOrder(BSTtree T){
	if(T != NULL){
		inOrder(T->lchild);
		printf("%d	", T->data);
		inOrder(T->rchild);
	}
}

// ���ô��� �βεĸı� ��Ӱ�� ʵ�ʲ����ĸı�
void deleteNode(BSTtree &bt){
	BSTNode *p;
	// ��ɾ���ڵ� �������� ��Ϊ�� 
	if(bt->lchild == NULL && bt->rchild == NULL){
		p = bt;
		bt = NULL;
		delete p;
	}
	// ��ɾ���ڵ� ������ Ϊ�� 
	else if(bt->lchild == NULL){
		p = bt;
		bt = bt->rchild;
		delete p;
	}
	// ��ɾ���ڵ� ������ Ϊ�� 
	else if(bt->rchild == NULL){
		p = bt;
		bt = bt->lchild;
		delete p;
	}
	// ��ɾ���ڵ� �������� ����Ϊ�� 
	else{
		/*
		// 1 ������ �� ����滻 
		BSTNode *parent = bt;
		// pre ָ�� bt�������� 
		BSTNode *pre = bt->lchild;
		// ������ �����ֵ �����滻 
		while(pre->rchild != NULL){
			parent = pre;
			pre = pre->rchild;
		}
		// while ѭ���������ҵ��� pre һ��ֻ������������������ 
		// �ҵ������������ֵ �滻 ��ɾ���ڵ�ֵ 
		bt->data = pre->data;
		
		// parent == bt����ʾ bt �������������ֵ ���� bt������ 
		if(parent == bt){
			parent->lchild = pre->lchild;
		}
		else{
			parent->rchild = pre->lchild;
		}
		delete pre; 
		*/
		
		// 2 ������ �� ��С�滻 
		BSTNode *parent = bt;
		// pre ָ�� bt�������� 
		BSTNode *pre = bt->rchild;
		// ������ ����Сֵ �����滻 
		while(pre->lchild != NULL){
			parent = pre;
			pre = pre->lchild;
		}
		// while ѭ���������ҵ��� pre һ��ֻ������������������ 
		// �ҵ������������ֵ �滻 ��ɾ���ڵ�ֵ 
		bt->data = pre->data;
		
		// parent == bt����ʾ bt �������������ֵ ���� bt������ 
		if(parent == bt){
			parent->rchild = pre->rchild;
		}
		else{
			parent->lchild = pre->rchild;
		}
		delete pre;
		//  
	}
} 

bool deleteBST(BSTtree &bt, dataType key){
	if(bt == NULL){
		return false;
	}
	else{
		if(bt->data == key){
			deleteNode(bt);
			return true;
		}
		else if(bt->data > key){
			return deleteBST(bt->lchild, key);
		}
		else{
			return deleteBST(bt->rchild, key);
		}
	} 
	
}


int main(){
	
	BSTtree T;
	
	int a[11] = {38, 12, 56, 6, 34, 40, 98, 3, 13, 78, 7};
	
	create_BST(T, a, 11);
	
	inOrder(T);
	
	printf("\n");
	
	bool flag = deleteBST(T, 38);
	if(flag == false){
		printf("ɾ��ʧ�ܣ�");
	}
	printf("\n");
	printf("T-data = %d	", T->data);
	
	inOrder(T);
	
	BSTNode* find = searchBST1(T, 70);
	
	if(find == NULL){
		printf("�޸ýڵ㣡");
	}
	else{
		printf("%d	", find->data);
	}
	
	return 0;
}
