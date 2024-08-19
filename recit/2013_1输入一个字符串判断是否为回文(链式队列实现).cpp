#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 20

typedef struct{
	char data[Max];
	int top;
}Stack;

void InitStack(Stack &s){
	s.top = -1;
}

bool isEmpty(Stack s){
	if(s.top == -1){
		return true;
	}
	return false;
}

bool isFull(Stack s){
	if(s.top == Max - 1){
		return true;
	}
	return false;
}

void Push(Stack &s, char value){
	if(isFull(s)){
		printf("ջ��"); 
		return; 
	}
	s.data[++s.top] = value;
	return;
}

void Pop(Stack &s, char &value){
	if(isEmpty(s)){
		printf("ջ��!");
		return;
	}
	value = s.data[s.top--];
	return;
}

typedef struct QuNode{
	int data;
	QuNode *next;
}QuNode, *QueuePtr;

typedef struct{
	// ͷ��βָ������ Ϊ QuNOde �ṹ������ 
	QueuePtr front;
	QueuePtr rear;
	int length; // ��¼ ���г��� 
}LinkQueue;

void InitQueue(LinkQueue &q){
	// ��ʼ�����ǹ���һ��ֻ��һ��ͷ���Ŀն�
	// �� ͷָ�롢βָ�� ָ�򴴽���ͷ�ڵ� 
	q.front = q.rear = (QuNode*) malloc(sizeof(QuNode));
	// �� ͷָ��ĺ�� ��Ϊ NULL������ q.front = NULL������д���� 
	q.front->next = NULL;
	q.length = 0;
}

bool isEmptyQueue(LinkQueue q){
	if(q.length == 0){
		return true;
	}
	return false;
}

void EnQueue(LinkQueue &q, char ch){
	QueuePtr s = (QuNode*) malloc(sizeof(QuNode));
	s->data = ch;
	s->next = NULL;
	// ��βָ�� ��ָ��ڵ�� ��� ָ�� s�ڵ� 
	q.rear->next = s;
	// βָ�� ���� 
	q.rear = q.rear->next;
	q.length++;
}

void DeQueue(LinkQueue &q, char &ch){
	if(isEmptyQueue(q)){ // q.front == q.rear
		printf("�ӿգ�");
		return;
	}
	// ����ҪΪ s ����洢�ռ䣬sֻ��һ��ָ�� 
	QueuePtr s = q.front->next;
	ch = s->data;
	// �� ���� ����������q.front ʼ��ָ�� ��ͷ�ڵ㣩 
	q.front->next = s->next; 
	// ɾ�����Ƕ����е����һ��Ԫ�� 
	if(q.rear == s){
		// �� βָ�� ָ�� ͷ�ڵ㣨ͷָ�� ָ���λ�ã� 
		q.rear = q.front;
	}
	free(s);
	q.length--;	
}

bool Symmetry(){
	Stack s;
	LinkQueue q;
	InitStack(s);
	InitQueue(q);
	
	char ch;
	ch = getchar();
	while(ch != '#'){
		Push(s, ch);
		EnQueue(q, ch);
		ch = getchar();
	}
	printf("���г��ȣ�%d\n", q.length);
	char ch1, ch2;
	// isEmpty(s)��ջΪ�գ�����true��ջ�ǿգ�����false 
	while(!isEmpty(s)){
		Pop(s, ch1);
		DeQueue(q, ch2);
		printf("ch1 = %c, ch2 = %c�����г��ȣ�%d\n", ch1, ch2, q.length);
		if(ch1 != ch2){
			return false;
		}
	}
	return true;
} 

int main(){

	// 	CHINABANIHC#
	// ABCDEFGHI#
	if(Symmetry()){
		printf("	yes		");
	}
	else{
		printf("	no		");
	}
	return 0;
}
