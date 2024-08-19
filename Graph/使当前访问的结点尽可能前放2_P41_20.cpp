#include<stdio.h>
#include <stdlib.h>

typedef struct lnode{
	int data, fre;
	lnode *prior,*next;
	
}lnode, *linklist;

int a[5] = {1, 2, 3, 4, 5};

int n = 5;

void buildList(linklist &L){
	L = (linklist) malloc(sizeof(lnode));
	lnode *r = L, *s;
	L->prior = NULL;
	L->next = NULL;
	
	/* 
	ѭ�� ˫���� 
	L->prior = L;
	L->next = L;
	*/
	 
	
	for(int i = 0; i < n; i++){
		// ��ʼ�� �ڵ�ֵ 
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		s->fre = 0;
		
		/*
		ѭ�� ˫���� 
		s->next = r->next;
		r->next->prior = s;
		r->next = s;
		s->prior = r;
		*/
		
		r->next = s;
		s->prior = r;
		
		r = s; 
	}
	
	r->next = NULL; // βָ��ĺ��ָ�� NULL 
	
}

void disp(linklist L){
	lnode *s = L->next;
	while(s){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

// ��Ҫ���ص��ǽڵ����� 
linklist Locate(linklist &L, int x){
	lnode *p = L->next, *q;
	while(p && p->data != x){
		p = p->next;
	}
	
	if(!p){
		printf("û�� %d ����ڵ�", x);
	}
	
	else{
		p->fre++;
		if(p->next != NULL){
			p->next->prior = p->prior;
		}
		// ���� p�ĺ���Ƿ�Ϊ�գ�p��ǰһ���ڵ� ָ�� p�ĺ�һ���ڵ� 
		p->prior->next = p->next;
			
		q = p->prior; // q ָ�� p�ڵ��ǰ��
			
		while(q != L && q->fre <= p->fre){ 
		// q ��Ϊͷ�ڵ㣬���� q��freֵ С�ڵ��� p��fre 
			q = q->prior; 
		}
		// �ҳ����� q��fre ���� p��fre  p ���� q �ĺ��� 
		p->next = q->next;
		q->next->prior = p;
		
		p->prior = q;
		q->next = p;
		
		return p;
	}
}

int main(){
	
	linklist L;
	buildList(L);
	disp(L);
	Locate(L, 5);
	disp(L);
	
	Locate(L, 4);
	Locate(L, 4);
	Locate(L, 3);
	Locate(L, 5);
	disp(L);
	
	return 0;
} 





