#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

void buildlist(linklist &L, int a[], int n){
	// �� ͷ�ڵ� 
	L = (lnode *) malloc(sizeof(lnode));
	// �洢��������� 
	L->data = n;
	L->next = NULL;
	lnode *s;
	lnode *r = L;
	
	for(int i = 0; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];

		r->next = s;
		r = r->next; 
	}
	r->next = NULL;
}

int main(){
	
	return 0;
} 
