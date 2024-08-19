#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[6] = {1, -4, 2, 3, 4, -2};

int n = 6;

void buildlist(linklist &L){
	// ���� ͷ�ڵ� 
	L = (linklist) malloc(sizeof(lnode));
	
	lnode *s,*r = L;
	
	for(int i = 0; i < n; i++){
		s = (lnode *)malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next; 
	}
	r->next = NULL;
} 

void disp(linklist L){
	lnode *s = L->next;
	while(s){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

void delete_same(linklist &L, int n){
	lnode *p = L;
	int *q;
	// ���� n + 1 ������ռ� 
	q = (int *)malloc(sizeof(int) * (n + 1));
	// ���� ��ʼ�� 
	for(int i = 0; i < n + 1; i++){
		*(q + i) = 0;
	} 
	
	int s;
	lnode *f;
	
	while(p->next != NULL){
		s = p->next->data > 0 ? p->next->data : -p->next->data;
		if(*(q + s) == 0){
			*(q + s) = 1;
			p = p->next;
		}
		else{
			// fָ�� ��ʱ���� ��ɾ���Ľ�� 
			f = p->next;
			p->next = f->next;
			free(f);
		}
	}
	// �ͷ� ��������ռ� 
	free(q);
}

int main(){
	
	linklist L;
	buildlist(L);
	
	disp(L);
	
	delete_same(L, 4);
	
	disp(L);
	
	return 0;
}
