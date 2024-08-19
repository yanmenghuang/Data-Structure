#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //��󶥵���Ϊ20
#define MaxInt 32767 //��ʾ�����������ʾ ��

typedef int VertexType;

//�������еĽ��
typedef struct ArcNode{	
	int adjvex;	//����ĵ�һ�ڽӵ���һά�����е��±�
	struct ArcNode *nextarc;	//ָ�򶥵����һ�ڽӵ�
	int weight;	//����Ϣ����Ȩֵ
}ArcNode;
	
//���㣨�洢��һά�����У�
typedef struct VNode{
	VertexType data;	//������Ϣ
	// ָ������Ϊ ArcNode�ṹ������ 
	ArcNode *firstarc;	//����ĵ�һ�ڽӵ�
}VNode,AdjList[VertexMax];	//AdjList��ʾ�ڽӱ�����

//�ڽӱ�
typedef struct{
	// AdjList[MVNum]���������ͣ������ÿһ��Ԫ��Ϊ VNode���� 
	AdjList vertices;	//һά����vertices
	int vexnum,arcnum;	//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

// ���� ����ͼ �ڽӱ� 
void CreateUDG(ALGraph *G){
	int i;
	//1.���붥�����ͱ��� 
	printf("���붥������ͱ�����\n");
	printf("������ n="); 
	scanf("%d",&G->vexnum);
	printf("���� e="); 
	scanf("%d",&G->arcnum);
	
	//������㣬����һά����
	for(i = 0; i < G->vexnum; ++i){
		// �����±� ���� ����ֵ 
		G->vertices[i].data = i;
		G->vertices[i].firstarc = NULL;	//��ʼ������ָ����
	}
	
	//������ߣ������ڽӱ�
	VertexType v1,v2;
	int weight;//v1->v2��Ȩֵ 
	int n,m;
	for(i = 0; i < G->arcnum; i++){
		printf("�����%d��·����Ϣ��",i+1);
	 	scanf("%d %d %d",&v1,&v2,&weight);
		
		// ����ߵ���Ϣ�Ƿ����������� 
	 	while(v1 < 0 || v1 > G->vexnum - 1 || v2 < 0 || v2 > G->vexnum - 1){
	 		printf("NO This Vertex!\n");
	 		printf("������ �����%d������Ϣ��Ȩֵ��",i+1);
	 		scanf("%d %d %d",&v1,&v2,&weight);
		} 
		ArcNode* p = (ArcNode*) malloc(sizeof(ArcNode));	//�����½��(ָ��p1ָ��ý�㣬��p1����ý��)
		p->adjvex = v2;	//�ڽӵ���һά�����е��±�ֵ��ֵ���ý��
		p->weight = weight; // Ȩֵ��Ϣ 
		// ���� ����ͷ�巨 
		p->nextarc = G->vertices[v1].firstarc;	
		G->vertices[v1].firstarc = p;	
	}
	return;
}

// ��� �ڽӱ� 
void printLG(ALGraph G){
	bool flag;
	for(int i = 0; i < G.vexnum; i++){
		flag = true;
		ArcNode* p = G.vertices[i].firstarc;
		if(p == NULL){
			printf("���� %d �ĳ���Ϊ 0", i);
			flag = false;
		}
		if(flag){
			printf("�� ���� %d �����ı��У�", i);
			while(p != NULL){
				printf("���� %d ������ %d��ȨֵΪ��%d ", i, p->adjvex, p->weight);
				p = p->nextarc;
			}
		}
		
		printf("\n");
	}
}

// ��� �ڽӱ� 
void printReverse(ALGraph G){
	bool flag;
	for(int i = 0; i < G.vexnum; i++){
		flag = true;
		ArcNode* p = G.vertices[i].firstarc;
		if(p == NULL){
			printf("���� %d �����Ϊ 0", i);
			flag = false;
		}
		if(flag){
			printf("���� %d ��ӵı��У�", i);
			while(p != NULL){
				printf("���� %d ������ %d��ȨֵΪ��%d ", p->adjvex, i, p->weight);
				p = p->nextarc;
			}
		}
		
		printf("\n");
	}
}

void Reverse(ALGraph GA, ALGraph &GB){
	GB.vexnum = GA.vexnum;
	GB.arcnum = GA.arcnum;
	//������㣬����һά����
	for(int i = 0; i < GB.vexnum; ++i){
		// �����±� ���� ����ֵ 
		GB.vertices[i].data = i;
		GB.vertices[i].firstarc = NULL;	//��ʼ������ָ����
	}
	for(int i = 0; i < GA.vexnum; i++){
		ArcNode* p = GA.vertices[i].firstarc;
		while(p != NULL){
			int j = p->adjvex;
			ArcNode* q = (ArcNode*) malloc(sizeof(ArcNode));
			q->adjvex = i;
			q->weight = p->weight;
			
			q->nextarc = GB.vertices[j].firstarc;
			GB.vertices[j].firstarc = q;
			
			p = p->nextarc;
		}
	}
}

int main(){
	
	ALGraph LA, LB;
	CreateUDG(&LA);
	printLG(LA);
	printf("\n");
	Reverse(LA, LB);
	printReverse(LB);
	
	return 0;
} 
