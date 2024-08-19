#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct treenode{
	char data;
	struct treenode *lchild, *rchild;
}treenode, *tree;

// pos:position(ע�⣺ȫ�ֱ���) 
int pos = 0;
// s:start(��ʼ����) e:end(��������) 
void build(char a[], char b[], int s, int e, tree &t){
	if(s <= e){
		t = (treenode *)malloc(sizeof(treenode));
		t->data = a[pos];
		int i;
		for(i = s; i <= e; i++){
			// ע�⣺ÿһ�εݹ���ã��� b����(��������) ���ҵ� "��ǰ" ���ڵ� 
			// i ͣ����λ�ã����Ǹ��ڵ��λ�� 
			if(b[i] == t->data){
				break;
			}
		}
		pos++;
		// ������������ֻ��Ҫ������������������ȥ�� 
		build(a, b, s, i-1, t->lchild);
		// ������������ֻ��Ҫ������������������ȥ�� 
		build(a, b, i+1, e, t->rchild);
	}
	else{
		t = NULL;
	}
	
}

void disp(tree t){
	if(t){
		disp(t->lchild);
		disp(t->rchild);
		printf("%c	", t->data);
	}
} 

int main(){
	tree t;
	// �������� 
	char a[] = {'A', 'B', 'D', 'E', 'C', 'F'}; 
	// �������� 
	char b[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	
	build(a, b, 0, 5, t);
	
	printf("�������У�");
	disp(t); 
	
	return 0;
}






