#include<iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

// �� �����ֵܱ�ʾ���洢ɭ�ֵ� Ҷ�ӽ����

/*
		�����û�к��ӣ����� ����Ҷ�ӡ� 
		�ܵ� Ҷ�ӽڵ��� = ���������ϵ�Ҷ���� + �ֵ������ϵ�Ҷ�ӽ���� 
*/ 

typedef struct treenode{
	char data;
	struct treenode *child, *brother;
}treenode, *tree; 

// ���� ��Ҫ������ &����Ϊ�����Ҫ���� 
void buildtree(tree &t){
	char ch;
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		// �����ڴ� 
		t = (treenode *)malloc(sizeof(treenode));
		// ��ֵ 
		t->data = ch;
		// ��ʼ�������ӡ����ֵ� �ֱ��ÿ� 
		t->child = NULL;
		t->brother = NULL;
		// �ݹ鸳ֵ 
		buildtree(t->child);
		buildtree(t->brother);
	}
}

void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->child);
		disp(t->brother);
	}
}

int Leaves(tree t){
	// ��Ϊ �� 
	if(t == NULL){
		return 0;
	}
	// �޺��ӽ�㣬��ǰ�ڵ� ��ԭɭ���� ��Ҷ�ӽڵ� 
	if(t->child == NULL){
		return 1 + Leaves(t->brother);
	}
	// �к��ӽ�� 
	else{
		return Leaves(t->child) + Leaves(t->brother);
	}
}

int count = 0;

void leaves(tree t){
	if(t){
		if(t->child == NULL){
			count++;
			leaves(t->brother);
		}
		else{
			leaves(t->child);
			leaves(t->brother);
		}
	}
}

int main(){
	
	tree t;
	// �������� GHK#L##I#JMP##N#O#### 
	buildtree(t);
	disp(t);
	printf("\n");
	leaves(t);
	printf("Ҷ�ӽ������%d\n", Leaves(t));
	printf("Ҷ�ӽ������%d", count);
	
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
