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
}VNode, AdjList[VertexMax];	//AdjList��ʾ�ڽӱ�����

//�ڽӱ�
typedef struct{
	// AdjList[MVNum]���������ͣ������ÿһ��Ԫ��Ϊ VNode���� 
	AdjList vertices;	//һά����vertices
	int vexnum,arcnum;	//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

typedef struct{
	VertexType Vertex[VertexMax];//��Ŷ���Ԫ�ص�һά���� 
	int AdjMatrix[VertexMax][VertexMax];//�ڽӾ����ά���� 
	int vexnum,arcnum;//ͼ�Ķ������ͱ���  
}MGraph;

// �ڽӱ� ת��Ϊ �ڽӾ��� 
void LGTransformV(ALGraph LG, MGraph *G){
	int i, j;
	// 1.������������ ��ֵ 
	G->vexnum = LG.vexnum;
	G->arcnum = LG.arcnum;
	
	// 2.���붥��Ԫ�� 
	for(i = 0; i < G->vexnum; i++){
		// �����±� ���� ����ֵ 
		G->Vertex[i] = i; 
	}
	
	// 3.�����ʼ��
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
	    	G->AdjMatrix[i][j] = MaxInt;
		}
	}
	// 4.�ڽӱ� ת��Ϊ �ڽӾ��� 
	for(i = 0; i < G->vexnum; i++){
		ArcNode* p = LG.vertices[i].firstarc;
		if(p == NULL){
			break;
		}
		while(p != NULL){
			G->AdjMatrix[i][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	} 
}

int main(){
	
	ALGraph LG;
	MGraph G;
	
	CreateUDG(LG);
	LGTransformV(LG, &G);
	
	return 0;
}


