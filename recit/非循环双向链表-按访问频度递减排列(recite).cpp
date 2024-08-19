#include<stdio.h>
#include <stdlib.h>
 
typedef struct lnode{
	int data, fre;
	lnode *prior,*next;
	
}lnode, *linklist;

// ����ͷ�ڵ�� ��ѭ�� ˫������ 
void buildList(linklist &L, int a[], int n){
	L = (linklist) malloc(sizeof(lnode));
	lnode *r = L, *s;
	L->prior = NULL;
	L->next = NULL;
	
	for(int i = 0; i < n; i++){
		// ��ʼ�� �ڵ�ֵ 
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		s->fre = 0;
		
		r->next = s;
		s->prior = r;
		
		r = s; 
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

linklist Locate(linklist &L, int x){
	// p������ָ�룬ָ�� data = x �Ľ�� 
	lnode *p = L->next, *q;
	while(p && p->data != x){
		p = p->next;
	}
	
	if(!p){
		printf("û�� %d ����ڵ�", x);
	}
	
	else{
		p->fre++;
		// p �ĺ�̷ǿ� 
		if(p->next != NULL){
			// p�ĺ�һ������ǰ�� ָ�� p��ǰһ����� 
			p->next->prior = p->prior;
		}
		// ���� p�ĺ���Ƿ�Ϊ�գ�p��ǰһ���ڵ�ĺ�� ָ�� p�ĺ�һ���ڵ� 
		p->prior->next = p->next;
		
		// q ָ�� p�ڵ��ǰһ����� 
		q = p->prior; 
		// ͬһ����Ƶ���£�������ʵ� �ŷ�����ǰ�� 
		while(q != L && q->fre <= p->fre){ 
		// q ��Ϊͷ�ڵ㣬���� q��freֵ С�ڵ��� p��fre 
			q = q->prior; 
		}
		// whileѭ��������q->fre > p->fre���� p��� ���� q��� �ĺ��� 
		p->next = q->next;
		q->next->prior = p;
		
		p->prior = q;
		q->next = p;
	}
	return p;
}

int main(){
	int a[5] = {1, 2, 3, 4, 5};
	int n = 5;
	
	linklist L;
	buildList(L, a, n);
	disp(L);
	Locate(L, 5);
	disp(L);

	lnode* p = Locate(L, 10);
	if(p){
		printf("%d	", p->data);
	}
	disp(L);
	
	return 0;
} 
