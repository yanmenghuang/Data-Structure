#include<stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

// ���ṹ��

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree; 

typedef struct{
	// ���Ľڵ�
	treenode *t;
	//  ���Һ��ӷ��ʱ��� tag = 0�����ӷ��ʹ���tag = 1���Һ��ӷ��ʹ�
	int tag; 
}Stack;

void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		// ���ڵ����ռ� 
		t = (treenode *)malloc(sizeof(treenode));
		// �Խڵ㸳ֵ 
		t->data = ch;
		// ���Һ����ÿ� 
		t->lchild = NULL;
		t->rchild = NULL;
		// �ݹ鸳ֵ���Һ��� 
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// �ٶ� X �� Y ����� 
treenode* Ancestor(tree t, char X, char Y){
	// ��������ջ
	Stack S1[10], S2[10]; // �ṹ������
	// ջ��ָ���ʼ��
	int top1 = -1, top2;
	// ������������ָ��
	treenode *p = t;
	// ��ѭ������������ǰ�����Ľڵ㲻��Ϊ�� ���� ջ1��ջ��ָ�� != -1(ջ��Ϊ��)
	while(p != NULL || top1 != -1){
		// ��������ѹ��ջ
		while(p != NULL){
			S1[++top1].t = p; // ѹ��ջ�� 
			S1[top1].tag = 0;  //��ʾ���ӷ��ʹ� 
			p = p->lchild;   // ����ָ������ 
		}
		// ջ1��Ϊ�� ���� tag = 1
		while(top1 != -1 && S1[top1].tag == 1){  
		
			// ���ջ���Ľڵ����p���͸��Ƶ�ջ2�У�ջ2��ջ��ָ�� ��ʱ��ֵ top1��ֵ
			if(S1[top1].t->data == X){
				for(int i = 0; i < top1; i++){
					S2[i] = S1[i];
					printf("S2[%d] = %c\n", i, S2[i].t->data);
				}
				top2 = top1;
			}
			// ���ջ���Ľڵ����q ��ջ1 ����ƥ�� 
			// Ҫ��������������ȣ��� ջ�����½���ƥ�� 
			if(S1[top1].t->data == Y){
				for(int i = top1 - 1; i > -1; i--){
					for(int j = top2; j > -1; j--){
						// ƥ��ɹ���ֱ�ӷ��� 
						if(S2[j].t->data == S1[i].t->data){
							return S1[i].t;
						}
					}
				}
			}
			// ��ջ
			top1--; 
		}
		
		// ջ����ʱ����ջ����tag = 1�����ҵ�ǰ�Ľڵ�ָ��ýڵ���Һ��� 
		if(top1 != -1){
			S1[top1].tag = 1;
			p = S1[top1].t->rchild;
		}
	}
	return NULL; // û�й������ȣ�����NULL 
} 

int main(){
	
	tree t;
	// �������У�FECA#B##D###HGJ##K##IL##M## 
	buildtree(t);

	tree ancestor = Ancestor(t, 'B', 'A');
	printf("%c", ancestor->data); 
	
	/*
					F
				E		 H
			 C        G     I
		  A    D    J   K  L M
		   B
	*/
	
	return 0;
}





