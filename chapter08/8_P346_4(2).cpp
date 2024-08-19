#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

void buildlist(lnode *L, int a[], int n){
	// ����ͷ�ڵ� ��ֻ��һ������ ���⴦�� 
	lnode *s;
	lnode *r = L;
	
	r->data = a[0];
	
	if(n == 1){
		r->next = NULL;
	}
	else{
		for(int i = 1; i < n; i++){
			s = (lnode *) malloc(sizeof(lnode));
			s->data = a[i];
	
			r->next = s;
			r = r->next; 
		}
		r->next = NULL;
	}
	
	
	
}

void disp(linklist L){
	lnode *p = L;
	while(p != NULL){
		printf("%d	", p->data);
		p = p->next;
	}
}

void SelectSort(linklist &L){
	lnode *h = L, *p, *pre_p, *max, *pre_max;
	// �� ���ÿ� 
	L = NULL;
	
	// �������ѭ������
	while(h != NULL){
		// ���ֵָ��  ����ָ���ʼ�� 
		max = h;
		p = h;
		
		pre_p = NULL;
		pre_max = NULL;
		// ÿһ�˿�ʼ����
		while(p != NULL){
			if(p->data > max->data){
				// �������ֵ���λ�� 
				max = p;
				pre_max = pre_p;
			}
			// ���� ����ָ��ǰ�� �� ����ָ��  
			pre_p = p;
			p = p->next;
		}
		
		// ����� �� ��ͷ��㣬��ͷ������ 
		if(max == h){
			h = h->next;
		} 
		else{
			// �� ����� ժ�������������� 
			pre_max->next = max->next;
		}
		
		// �� ����� ���� 
		max->next = L;
		// L ָ����� 
		L = max; 
	} 
}

int main(){
	int a[10] = {9, 7, 5, 6, 3, 4, 1, 2, 8};
	
	lnode list;
	lnode *L = &list;
	
	buildlist(L, a, 9);
	
	disp(L);
	
	printf("\n");
	
	SelectSort(L); 
	
	disp(L);
	
	return 0;
}
