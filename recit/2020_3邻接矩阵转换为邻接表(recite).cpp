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

// �ڽӾ��� 
typedef struct{
	VertexType Vertex[VertexMax];//��Ŷ���Ԫ�ص�һά���� 
	int AdjMatrix[VertexMax][VertexMax];//�ڽӾ����ά���� 
	int vexnum, arcnum;//ͼ�Ķ������ͱ���  
}MGraph;

// �ڽӾ��� ת��Ϊ �ڽӱ� 
void VGTransformLG(MGraph G, ALGraph *LG){
	int i, j;
	//1.������������ ��ֵ 
	LG->vexnum = G.vexnum;
	LG->arcnum = G.arcnum;
	
	//������㣬����һά����
	for(i = 0; i < LG->vexnum; ++i){
		// �����±� ���� ����ֵ 
		LG->vertices[i].data = i;
		LG->vertices[i].firstarc = NULL;	//��ʼ������ָ����
	}
	
	for(i = 0; i < G.vexnum; i++){
		for(j = 0; j < G.vexnum; j++){
			// ���� i �� ���� j ֮����ڱ� 
			if(G.AdjMatrix[i][j] != MaxInt){
				//�����½��(ָ��p1ָ��ý��
				ArcNode* p = (ArcNode*) malloc(sizeof(ArcNode));
				p->adjvex = j;	//�ڽӵ���һά�����е��±�ֵ��ֵ���ý��
				p->weight = G.AdjMatrix[i][j]; // Ȩֵ��Ϣ 
				// ���� ����ͷ�巨 
				p->nextarc = LG->vertices[i].firstarc;	
				LG->vertices[i].firstarc = p;	
			}
		}
	}
}

int main(){
	
	ALGraph LG;
	MGraph G;
	
	Create(G);
	VGTransformLG(G, &LG);

	return 0;
} 

