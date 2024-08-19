#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

// �����ֵܱ�ʾ�������������

/*
		���գ����� 0.
		�߶�Ϊ ��һ��Ů���߶� + 1  �� �ֵ������߶�  �Ĵ��� 
*/ 

typedef struct treenode{
	char data;
	struct treenode *child, *brother;
}treenode, *tree;
// treenode����ʾ���  *tree����ʾ��

void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->child = NULL;
		t->brother = NULL;
		
		buildtree(t->child);
		buildtree(t->brother);
	}
} 

int height(tree t){
	if(t == NULL){
		return 0;
	}
	else{
		// �������Ӹ߶� 
		int l = height(t->child);
		// �������ֵܸ߶� 
		int r = height(t->brother);
		
		return l + 1 > r ? l + 1 : r; 
	}
}

int main(){
	
	tree t;
	// �������� GHK#L##I#JMP##N#O####  
	buildtree(t);
	printf("���ߣ�%d", height(t));
	
	return 0;
	
	/*
	������ P175 
					G
				H
			K	  I
			  L     J
			      M
			    P   N
			          O
					
					
					G
			  H     I	   J
			K   L       M  N  O
			            P
	*/
}
