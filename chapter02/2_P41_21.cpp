#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// �� ���� 

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9};

int n = 15;

void buildlist(lnode *L){
	lnode *s, *r = L;
	
	r->data = a[0];
	
	for(int i = 1; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next;
	}
	// β����ָ������Ϊ NULL����ֹ����ָ�� 
	r->next = NULL;
}

void disp(lnode *L){
	lnode *s = L;
	while(s){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

// ���ؽ�㣺������� 
lnode* findnode(lnode *L){
	// f����ָ��   s����ָ�� 
	lnode *f = L, *s = L;
	printf("%d	test", s->data);
	while(s != NULL && f->next != NULL){
		
		// sָ����һ��  fָ�������� 
		s = s->next;
		f = f->next->next; 
		if(s->data == f->data){
			printf("������");
			break;
		}
		// ��ָ�� ���� ��ָ�� Ϊ NULL��˵��û�л� 
		if(s == NULL || f == NULL){
			return NULL;
		}
		
		lnode *p = L, *q = s;
		while(p->data != q->data){
			p = p->next;
			q = q->next;
		} 
		return p;
	} 
}

int main(){
	
	lnode list;
	lnode *L = &list;
	
	buildlist(L);
	
	disp(L);
	lnode *ans = findnode(L);
	printf("����ֵΪ��%d", ans->data);
	
	return 0;
}
