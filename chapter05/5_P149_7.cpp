#include<stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 15

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

struct squeue{
	struct treenode* data[Max];
	int f,r;
	// ��־ 
	int tag;
};

bool isEmpty(squeue s){
	if(s.f == s.r && s.tag == 0){
		// �ӿ� 
		return true;
	}
	// �ӷǿ� 
	return false;
}

bool isFull(squeue s){
	if(s.f == s.r && s.tag == 1){
		// ���� 
		return true;
	}
	// ��δ�� 
	return false;
} 

bool enters(squeue &s, treenode *p){
	if(isFull(s)){
		// ���� 
		return false;
	}
	s.data[s.r] = p;
	// βָ����� 
	s.r = (s.r + 1) % Max;
	// ֻ�� ��� �ſ���ʹ ���� 
	// ��ӽ� tag ֵ ��Ϊ 1 
	s.tag = 1;
	return true;
}

bool outs(squeue &s, treenode *p){
	if(s.f == s.r && s.tag == 0){
		return false;
	}
	// �� p��� ���� ���ӽ�� 
	p = s.data[s.f];
	s.f = (s.f + 1) % Max;
	// ֻ�� ���� �ſ���ʹ �ӿ� 
	s.tag = 0;
	
	return true;
}

bool isok(tree t){
	squeue s;
	s.f = s.r = 0;
	s.tag = 0;
	// flag Ϊ true ��ʾ��֮ǰ�����Ľ�� �������Һ���  
	bool flag = true;
	// ������� 
	bool ans = true;

	// ���� 
	if(t == NULL){
		ans = true;
	}
	// ֻ�� ����� 
	if(t->lchild == NULL && t->rchild == NULL){
		ans = true;
	}
	// ����� ��� 
	enters(s, t);
	// printf("%c	", s.data[s.f]->data);
	treenode *p;
	
	// ���в�Ϊ��ʱ��whileִ�� 
	while(isEmpty(s) == false){
		
		outs(s, p);
		
		if(!p->lchild){ // ȱ ���� 
			flag = false;
			if(p->rchild){
				// ȱ ���ӣ� �� �Һ��ӣ�������ȫ������ 
				ans = false;
			}
		}
		// ��ǰ��� �� ���� 
		else{
			// flag == true����ʾ ֮ǰ������ ȱ���� ��� 
			if(flag){
				enters(s, p->lchild); // ���� ���� 
				if(p->rchild){
					// �Һ��� ���� 
					enters(s, p->rchild);
				}
				else{
					// �����ӣ����Һ��� 
					flag = false;
				} 
			} 
			// ֮ǰ���� ȱ���ӵĽ�� 
			else{
				ans = false; 
			} 
		} 
	}
	if(ans){
		return true;
	}
	else{
		return false;
	}
	 
}

void disp(tree t){
	if(t){
		printf("%c	", t->data);
		disp(t->lchild);
		disp(t->rchild);
	}	
}


int main(){
	
	tree t;
	// ABD##E##CF##G##
	buildtree(t);
	
	disp(t);
	
	if(isok(t)){
		printf("yes!!!");
	}
	else{
		printf("no!!!");
	}
	
	return 0;
}
