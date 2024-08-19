#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int n = 8; 

void buildList(linklist &L){
	// L��ָ��Ľ�� Ϊ ͷ�ڵ� 
	L = (linklist)malloc(sizeof(lnode));
	
	lnode *s;
	lnode *r = L;
	for(int i = 0; i < n; i++){
		s = (lnode *)malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next; 
	}
	
	r->next = NULL;
}

// ����һ��ͷ�巨 
linklist reverse_list1(linklist &L){
	lnode *p = L->next;
	lnode *r;
	
	// ͷ�ڵ�ĺ�� �ÿ� 
	L->next = NULL;
	
	while(p != NULL){
		// r ָ�� p �ĺ�һ����㣬��ֹ���� 
		r = p->next;
		
		p->next = L->next;
		L->next = p;
		
		p = r; 
	}
	
	return L;
}

// ������ 
linklist reverse_list2(linklist &L){
	lnode *pre;
	lnode *p = L->next;
	lnode *r = p->next;
	
	p->next = NULL;
	
	while(r != NULL){
		pre = p;
		p = r;
		r = r->next;
		
		p->next = pre;
	}
	// �� ͷ�ڵ�� ��� ָ�� p��� 
	L->next = p;
	
	return L;
}

void disp(linklist L){
	lnode *s = L->next;
	while(s){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

int main(){
	
	lnode list;
	lnode *L = &list;
	
	buildList(L);
	
	disp(L);
	
	reverse_list1(L);
	
	disp(L);
	
	reverse_list2(L);
	
	disp(L);
	
	return 0;
}
