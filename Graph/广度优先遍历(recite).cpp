#include <stdio.h>
#include <stdlib.h>
#define VertexMax 100 //��󶥵���Ϊ100
#define Maxsize 100 //�������Ԫ�ظ���100 

typedef int VertexType; //ÿ��������������Ϊ�ַ��� 
typedef int dataType; //����Ԫ������ 

/*ͼ�ṹ��*/
typedef struct{
	VertexType Vertex[VertexMax];//��Ŷ���Ԫ�ص�һά���� 
	int AdjMatrix[VertexMax][VertexMax];//�ڽӾ����ά���� 
	int vexnum,arcnum;//ͼ�Ķ������ͱ���  
}MGraph;

/*���нṹ��*/
typedef struct{
	dataType *base;
	int front;
	int rear;
	int tag;
}CyQueue;

/*ѭ�����л�������*/
void create(CyQueue &q)
{
	q.base = (dataType *)malloc(Maxsize*sizeof(dataType));
	if(!q.base)
	{
		printf("Space allocation failed!\n");
		return;
	}
	q.front = q.rear = 0;
	q.tag = 0;
	return;
}

void EnQueue(CyQueue &q, dataType value){
	if(q.rear == q.front && q.tag == 1){
		printf("Cyclic Queue is Full!\n");
		return;
	}
	q.base[q.rear] = value;
	q.rear = (q.rear+1) % Maxsize;
	q.tag = 1;
	return;
}

void DeQueue(CyQueue &q, dataType &value){
	if(q.front == q.rear && q.tag == 0){
		printf("Cyclic Queue is Empty!\n");
		return;
	}
	value = q.base[q.front];
	q.front = (q.front+1) % Maxsize;
	q.tag = 0;
	return;
} 

int QueueEmpty(CyQueue q){
    if (q.front == q.rear && q.tag == 0)//����Ϊ�շ���1����Ϊ�շ���0 
	{
        return 1;
    }
    return 0;
}

/*������ȱ���BFS*/ 
int visited[VertexMax];//����"��־"����Ϊȫ�ֱ��� 

void BFS(MGraph *G,int i){
	int j;
	CyQueue q;
	create(q);
   //1.������ʼ�� 
	printf("%d	",G->Vertex[i]);//1.�����ǰ��� 
	visited[i]=1;//2.���ѷ��ʵĽ���־��1
	EnQueue(q,i);//3.����һ�������� 
    
    //2.����ʼ�㿪ʼ���Ժ��������в���
	while(!QueueEmpty(q)){
		
		DeQueue(q,i);
		
		for(j=0;j<G->vexnum;j++){
			if(G->AdjMatrix[i][j]==1&&visited[j]==0){
				printf("%d	",G->Vertex[j]);//������������Ķ��� 
	            visited[j]=1;//���ó��ѷ���״̬1 
	            EnQueue(q,j);//��� 
			}
		}
	} 	
} 

void BFSTraverse(MGraph *G, int start)
{
	int i;
	
	//�����ʼ��Ϊȫ0 
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0;
	} 
	
	BFS(G,start);
	for(i = 0; i < G->vexnum; i++){
		if(visited[i] == 0){
			BFS(G,i);
		}
	}
} 

int main() 
{
	MGraph G; 
	CreateUDG(&G);
	print(G); 
	
	printf("\n\n������ȱ�����"); 
	int start = 5
	BFSTraverse(&G, start); 
	 
	return 0;
}	
