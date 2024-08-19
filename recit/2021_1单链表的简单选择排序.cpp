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

void disp(linklist L){
	lnode *p = L->next;
	while(p != NULL){
		printf("%d	", p->data);
		p = p->next;
	}
	printf("\n"); 
}

// ѡ������ÿ��ѡ��� ��ǰ���ֵ����������� ͷ�巨 
void SelectSort(linklist &L){
	lnode *h = L->next, *p, *pre_p, *max, *pre_max;
	// �� ���ÿ� 
	L->next = NULL;
	// �������ѭ������
	while(h != NULL){
		// ���ֵָ���ʼ�������ֵ��ʼΪ��һ���ڵ�ֵ  
		max = h;
		// ����ָ���ʼ�� 
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
			pre_max->next = max->next;
		}
		// �� ����� ���� 
		max->next = L->next;
		L->next = max; 
	} 
}

int main(){
	int a[5] = {4, 3, 5, 2, 1};
	
	linklist L;
	
	buildlist(L, a, 5);
	
	disp(L);
	
	SelectSort(L); 
	
	disp(L);
	
	return 0;
}
