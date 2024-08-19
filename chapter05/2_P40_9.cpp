#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct lnode{
	int data;
	lnode *next;
}lnode, *linklist;

void buildlist(linklist &L, int a[], int n){
	L = (linklist) malloc(sizeof(lnode));
	lnode *r = L, *s;
	for(int i = 0; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void delete_min(linklist &L){
	while(L->next != NULL){
		lnode *pre = L, *p = L->next;
		// ��ǰ������һ����� ��Ϊ�� 
		while(p->next != NULL){
			// pre ָ����� ��ǰ��С����ǰ�� 
			if(pre->next->data > p->next->data){
				// ��¼ ��ǰ��Сֵ��� ��ǰ�� 
				pre = p;
			}
			p = p->next; 
		}
		printf("%d	", pre->next->data);
		// ��ֹ ���� 
		lnode *q = pre->next;
		pre->next = q->next;
		free(q);
	}
	free(L); 
}

int main(){
	
	linklist L;
	
	int a[5] = {2, 5, 3, 8, 1};
	int n = 5;
	
	buildlist(L, a, n);
	
	delete_min(L); 
	
	return 0;
} 
