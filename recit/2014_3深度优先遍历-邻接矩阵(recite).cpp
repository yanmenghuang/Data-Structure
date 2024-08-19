#include <stdio.h>
#include <stdlib.h>
#define VertexMax 100 //��󶥵���Ϊ100

typedef int VertexType; //ÿ��������������Ϊ�ַ��� 

typedef struct
{
	VertexType Vertex[VertexMax];//��Ŷ���Ԫ�ص�һά���� 
	int AdjMatrix[VertexMax][VertexMax];//�ڽӾ����ά���� 
	int vexnum,arcnum;//ͼ�Ķ������ͱ���  
}MGraph;

/*������ȱ���DFS*/ 
// �� �����±� ��ʾ ���� 
int visited[VertexMax];//����"��־"����Ϊȫ�ֱ��� 

void DFS(MGraph *G,int i){
	int j;
	
	//1.������ʼ�� 
	printf("%d	",G->Vertex[i]);//1.�����ʼ��� 
	visited[i] = 1;//2.���ѷ��ʵĽ���־��1
	
	//2.����ʼ�㿪ʼ���Ժ��������в���
	//��������vi���ڽӵ� 
	for(j = 0; j < G->vexnum; j++){
		//�������б���δ�����ʹ�ʱ���ݹ����ȥ���Ҹ��ڽӵ� 
		if(G->AdjMatrix[i][j] == 1 && visited[j]==0){
			// �ݹ���� 
			DFS(G,j);//ע��˴���G�Ѿ���ָ�����ͣ�����Ҫ��&G 
		}
	}
	// ���б� ���������ʹ�ʱ ���� �ޱߣ��ݹ������������һ�� 
}

void DFSTraverse(MGraph *G, int start){
	int i;
	//��ʼ��"��־"����Ϊ0������δ����
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0; 
	} 
	
	// �� ָ������ ���� 
	DFS(G,start);
	visited[start] = 1;
	// forѭ������ֹͼ�Ƿ���ͨͼ��һ�εݹ���ò���ȫ�������� 
	for(i = 0; i < G->vexnum; i++){
		if(visited[i] == 0){
			DFS(G, i);
		}
	} 
}

int main() 
{
	MGraph G;
	CreateUDG(&G);
	print(G); 

	printf("\n\n������ȱ�����");
	int start = 6; 
	DFSTraverse(&G, start); 
	 
	return 0;
}	
