#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //��󶥵���Ϊ20
#define MaxInt 32767 //��ʾ�����������ʾ ��

typedef int VertexType;

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
	AdjList vertices;	//һά����vertices
	int vexnum, arcnum;	//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

/*������ȱ���*/
int visited[VertexMax]; //��������Ϊȫ�ֱ��� 

void DFS(ALGraph *G, int i){
	int j;
	ArcNode* p;
	int w;
	
	//1.���ʵ�ǰ�ڵ� 
	printf("%c	", G->vertices[i].data);
	//2.����ǰ�ڵ��ǳ��ѷ��ʽ��
	visited[i] = 1;
	
	p = G->vertices[i].firstarc;
	while(p != NULL){
		w = p->adjvex;//w ���ڽӵ������ 
		if(visited[w] == 0){
			DFS(G, w);
		}
	    p = p->nextarc;//������֮�󣬽�p�����һλ 
	} 
} 

void DFSTraverse(ALGraph *G, int start){
	int i;
	
	//��ʼ��"��־"����
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0;
	} 
	
	// �� ָ������ ���� 
	DFS(G, start);
	
	// forѭ������ֹͼ�Ƿ���ͨͼ��һ�εݹ���ò���ȫ�������� 
	for(i = 0; i < G->vexnum; i++){
		if(visited[i] == 0){
			DFS(G, i);
		}
	}
}

int main(){
 	ALGraph G;
 	CreateUDG(&G);
	int start = 0;
	printf("\n\n������ȱ�����"); 
	DFSTraverse(&G, start);  
 	
	return 0;
}

