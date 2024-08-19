#include <stdio.h>
#include <stdlib.h>
#define VertexType char //������������ͣ�char�� 
#define VertexMax 20 //��󶥵���� 

//�߱� 
typedef struct ArcNode{
	int adjvex;//�洢���Ǹö����ڶ������鼴AdjList[]�е�λ�� 
	struct ArcNode *next;
}ArcNode;

//�������� 
typedef struct VNode {
	VertexType vertex;
	struct ArcNode *firstarc;
}VNode;

//����� 
typedef struct{
	VNode AdjList[VertexMax];//�ɶ��㹹�ɵĽṹ������ 
	int vexnum,arcnum; //�������ͱ��� 
	int kind; //��¼ͼ������ 
}ALGraph;

int LocateVex(ALGraph *G, VertexType v){    
    int i;
	for(i=0;i<G->vexnum;i++)
	{
		if(v==G->AdjList[i].vertex)
		{
			return i;
		}
	}
	
	printf("No Such Vertex!\n");
	return -1;
}

//1.����ͼ 
void CreateDG(ALGraph *G){
	int i,j;
	//1.���붥�����ͱ��� 
	printf("���붥������ͱ�����\n");
	printf("������ n="); 
	scanf("%d",&G->vexnum);
	printf("��  �� e="); 
	scanf("%d",&G->arcnum);
	printf("\n"); 
	
	printf("\n");
	//2.�������������ֵ��ʼ�������ָ���� 
	printf("���붥��Ԫ��(�ÿո����)��");
	for(i=0;i<G->vexnum;i++)
	{
		scanf(" %c",&G->AdjList[i].vertex);
		G->AdjList[i].firstarc=NULL;
	} 
	printf("\n");
	
	//3.�������Ϣ�����ڽӱ� 
	int n,m;
	VertexType v1,v2;
	ArcNode *p1,*p2; 
	
	printf("������ߵ���Ϣ��\n\n"); 
	for(i=0;i<G->arcnum;i++)
	{   //�������Ϣ����ȷ��v1��v2��G�е�λ�ã���������AdjList[]�����е�λ�ã��±꣩  
		printf("�����%d������Ϣ��",i+1); 
		scanf(" %c%c",&v1,&v2);
		n=LocateVex(G,v1);
		m=LocateVex(G,v2);
		
		if(n==-1||m==-1)
		 {
		 	printf("NO This Vertex!\n");
		 	return;
		 } 
		
		p1=(ArcNode *)malloc(sizeof(ArcNode));
		p1->adjvex=m;//�������� 
		p1->next=G->AdjList[n].firstarc;//������ͷ�巨��  
		G->AdjList[n].firstarc=p1;
	
	}//for  
	G->kind=1;
} 

//2.����ͼ 
void CreateUDG(ALGraph *G)
{
	int i,j;
	//1.���붥�����ͱ���
	printf("���붥������ͱ�����\n");
	printf("������ n="); 
	scanf("%d",&G->vexnum);
	printf("��  �� e="); 
	scanf("%d",&G->arcnum);
	printf("\n"); 
	
	printf("\n");
	//2.�������������ֵ��ʼ�������ָ����
	printf("���붥��Ԫ��(����ո����)��");
	for(i=0;i<G->vexnum;i++)
	{
		scanf(" %c",&G->AdjList[i].vertex);
		G->AdjList[i].firstarc=NULL;
	} 
	printf("\n");
	
	//3.�������Ϣ�����ڽӱ�
	int n,m;
	VertexType v1,v2;
	ArcNode *p1,*p2; 
	
	printf("������ߵ���Ϣ��\n\n"); 
	for(i=0;i<G->arcnum;i++)
	{   //�������Ϣ����ȷ��v1��v2��G�е�λ�ã���������AdjList[]�����е�λ�ã��±꣩ 
		printf("�����%d������Ϣ��",i+1); 
		scanf(" %c%c",&v1,&v2);
		n=LocateVex(G,v1);
		m=LocateVex(G,v2);
		
		if(n==-1||m==-1)
		 {
		 	printf("NO This Vertex!\n");
		 	return;
		  } 
		
		p1=(ArcNode *)malloc(sizeof(ArcNode));
		p1->adjvex=m;//�������� 
		p1->next=G->AdjList[n].firstarc;//������ͷ�巨�� 
		G->AdjList[n].firstarc=p1;
		
		p2=(ArcNode *)malloc(sizeof(ArcNode));//����ͼ�ĶԳ� 
		p2->adjvex=n;
		p2->next=G->AdjList[m].firstarc;
		G->AdjList[m].firstarc=p2;
		
	}//for 
	G->kind=2; 
} 

void print(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("\n-------------------------------");
	printf("\nͼ���ڽӱ��ʾ��\n");
	
	for(i=0;i<G.vexnum;i++)
	{
		printf("\n   AdjList[%d]%4c",i,G.AdjList[i].vertex);
		p=G.AdjList[i].firstarc;
		
		while(p!=NULL)
		{
			printf("-->%d",p->adjvex);
			p=p->next;
		}
	 } 
	 printf("\n");
} 

void GraphChoice(ALGraph *G)
{
	int target;
    printf(" ��ѡ��ͼ�����ͣ�1.����ͼDG  2.����ͼUDG\n\n");
    scanf("%d",&target);//ѡ��ͼ������ 
    printf("\n");

    switch (target) //������ѡ���ͣ����ò�ͬ�ĺ���ʵ�ֹ���ͼ�Ĺ��� 
	{
        case 1:
        	 printf("��ѡ����� 1.DG\n\n"); 
        	 printf("-------------------------------\n");
             CreateDG(G);
            break;
        case 2:
        	 printf("��ѡ����� 2.UDG\n\n"); 
        	 printf("-------------------------------\n");
             CreateUDG(G);
            break;
        default:
        	printf("��Чѡ��!!!������ѡ��\n\n"); 
        	printf("-------------------------------\n");
			GraphChoice(G);   
            break;
    }
}

int main() 
{
	ALGraph G;
	GraphChoice(&G);
	print(G);
	
	return 0;
}

