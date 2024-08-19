#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct lnode{
	int data;
	struct lnode *next;
}lnode, *linklist;

int a[5] = {3, 1, 6, 4, 8};

int n = 5;

void buildlist(linklist &L){
	// ���� ͷ�ڵ� 
	L = (linklist) malloc(sizeof(lnode));
	lnode *s;
	lnode *r = L;
	
	for(int i = 0; i < n; i++){
		s = (lnode *) malloc(sizeof(lnode));
		s->data = a[i];
		// β�巨 
		r->next = s;
		r = r->next;
	}
	// �� βָ�� ָ�� ͷ�ڵ㣬���� ѭ������ 
	r->next = L;
}

void disp(linklist L){
	lnode *s = L->next;
	while(s != L){
		printf("%d	", s->data);
		s = s->next;
	}
	printf("\n");
}

void delete_min(linklist &L){
	lnode *p;
	lnode *pre;
	
	lnode *min;
	lnode *pre_min;
	
	while(L->next != L){
		// ÿһ�α������� p ��ʼ��ָ�� ��һ�� Ԫ�ؽ�� 
		p = L->next; 
		pre = L;
		// ��ʼʱ����Сֵ ��Ϊ ��һ�����ֵ 
		min = p;
		pre_min = pre;
		while(p != L){
			// ��ǰ���ֵ < ��С���ֵ 
			if(p->data < min->data){
				min = p;
				pre_min = pre;
			}
			pre = p;
			p = p->next;
		}
		printf("��ǰ��СԪ�أ�%d\n", min->data);
		pre_min->next = min->next;
		// �ͷ� ��ǰ��Сֵ ��� 
		free(min);
		
		disp(L); 
	}
	// �ͷ�ͷ�ڵ� 
	free(L); 
	
}

int main(){

	linklist L;
	buildlist(L);
	
	disp(L);
	
	delete_min(L);
	
	return 0;
} 
