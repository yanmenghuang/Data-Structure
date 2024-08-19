#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //��󶥵���Ϊ20
#define MaxInt 32767 //��ʾ�����������ʾ ��
#define Maxsize 100 //�������Ԫ�ظ���100

typedef int VertexType; //ÿ��������������Ϊ�ַ��� 
typedef int dataType; //����Ԫ������ 

//�������еĽ��
typedef struct ArcNode{	
	int adjvex;	// �û���ָ��Ķ����λ�� 
	struct ArcNode *nextarc;	//ָ����һ������ָ�� 
	int weight;	//����Ϣ����Ȩֵ
}ArcNode;
	
//���㣨�洢��һά�����У�
typedef struct VNode{
	VertexType data; //������Ϣ
	// ָ������Ϊ ArcNode�ṹ������ 
	ArcNode *firstarc;	//����ĵ�һ�ڽӵ�
}VNode,AdjList[VertexMax];	//AdjList��ʾ�ڽӱ�����

//�ڽӱ�
typedef struct{
	// AdjList[MVNum]���������ͣ������ÿһ��Ԫ��Ϊ VNode���� 
	AdjList vertices;	//һά���� vertices
	int vexnum, arcnum;	//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

/*���нṹ��*/
typedef struct{
	dataType *base;
	int front;
	int rear;
	int tag;
}Queue;

/*ѭ�����л�������*/
void InitQueue(Queue &q){
	q.base = (dataType *)malloc(Maxsize *sizeof(dataType));
	if(!q.base){
		printf("�ڴ����ʧ��!\n");
		return;
	}
	q.front = q.rear = 0;
	q.tag = 0;
	return;
}

void EnQueue(Queue &q, dataType value){
	if(q.rear == q.front && q.tag == 1){
		printf("����!\n");
		return;
	}
	q.base[q.rear] = value;
	q.rear = (q.rear+1) % Maxsize;
	q.tag = 1;
	return;
}

void DeQueue(Queue &q, dataType &value){
	if(q.front == q.rear && q.tag == 0){
		printf("�ӿ�!\n");
		return;
	}
	value = q.base[q.front];
	q.front = (q.front+1) % Maxsize;
	q.tag = 0;
	return;
} 

bool isEmpty(Queue q){
    if (q.front == q.rear && q.tag == 0){
        return true;
    }
    return false;
}

/*������ȱ���*/
int visited[VertexMax]; //��������Ϊȫ�ֱ��� 

void BFS(ALGraph *G, int i){
	int j;
	struct ArcNode *p;
	Queue q;
	InitQueue(q);
	
    //1.������ʼ��
	printf("%d	",G->vertices[i].data);//1.�����ʼ���
	visited[i] = 1;//2.���ѷ��ʵĽ���־�� 1
	EnQueue(q, i);//3.����һ�������� 

    //2.����ʼ�㿪ʼ���Ժ��������в���
	while(!isEmpty(q)){
		DeQueue(q, i);
		
		p = G->vertices[i].firstarc;
		
		while(p != NULL){
			
			if(visited[p->adjvex] == 0){
				printf("%d	", G->vertices[p->adjvex].data);
	            visited[p->adjvex] = 1;
	            EnQueue(q, p->adjvex);
			}
			p = p->nextarc;//������֮�󣬽�p�����һλ 
		}
	} 	
} 

void BFSTraverse(ALGraph *G){
	int i;
	
	//�����ʼ��Ϊȫ0 
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0;
	} 
	
	for(i = 0; i < G->vexnum; i++){
		if(visited[i] == 0){
			BFS(G, i);
		}
	}
} 

int main() {
	ALGraph G; 
	// CreateUDG(&G);
	
	printf("\n\n������ȱ�����"); 
	BFSTraverse(&G); 
	 
	return 0;
}	

