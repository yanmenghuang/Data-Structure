#include <stdio.h>
#include <stdlib.h>
#define VertexMax 100 //��󶥵���Ϊ100

typedef int VertexType; //ÿ��������������Ϊ�ַ��� 

typedef struct{
	VertexType Vertex[VertexMax];//��Ŷ���Ԫ�ص�һά���� 
	int AdjMatrix[VertexMax][VertexMax];//�ڽӾ����ά���� 
	int vexnum, arcnum;//ͼ�Ķ������ͱ���  
}MGraph;

//����ͼ
void CreateUDG(MGraph *G){
	int i,j;

	printf("���붥������ͱ�����\n");
	printf("������ n="); 
	scanf("%d", &G->vexnum);
	printf("��  �� e="); 
	scanf("%d", &G->arcnum);
	printf("\n"); 
	
	for(i = 0; i < G->vexnum; i++){
		G->Vertex[i] = i;
	}
	
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
	    	G->AdjMatrix[i][j] = 0;
		}
	}
	VertexType v1,v2;
	 
	printf("������ߵ���Ϣ��\n");
	// forѭ�������� 
	for(i = 0; i < G->arcnum; i++){
		printf("�����%d������Ϣ��Ȩֵ��",i+1);
	 	scanf("%d %d",&v1,&v2);
	 	
	 	
	 	// ����ߵ���Ϣ�Ƿ����������� 
	 	while( v1 < 0 || v1 > G->vexnum - 1 || v2 < 0 || v2 > G->vexnum - 1){
	 		printf("NO This Vertex!\n");
	 		printf("������ �����%d���ߵĶ�����Ϣ��",i+1);
	 		scanf("%d %d",&v1,&v2);
		} 
	 	
		G->AdjMatrix[v1][v2] = 1;
	   	G->AdjMatrix[v2][v1] = 1;
     } 
}


/*������ȱ���DFS*/ 
// �� �����±� ��ʾ ���� 
int visited[VertexMax];//����"��־"����Ϊȫ�ֱ��� 

void DFS(MGraph *G, int i){
	int j;
	
	//1.������ʼ�� 
	printf("%d	",G->Vertex[i]);//1.�����ʼ��� 
	visited[i] = 1;//2.���ѷ��ʵĽ���־��1
	
	//2.����ʼ�㿪ʼ���Ժ��������в���
	//��������vi���ڽӵ� 
	for(j = 0; j < G->vexnum; j++){
		//�������б���δ�����ʹ�ʱ���ݹ����ȥ���Ҹ��ڽӵ� 
		if(G->AdjMatrix[i][j] == 1 && visited[j] == 0){
			// �ݹ���ã��� ���� j ��ʼ 
			DFS(G, j);
		}
	}
	// ���б� ���������ʹ�ʱ ���� �ޱߣ��ݹ������������һ�� 
}

void DFSTraverse(MGraph *G, int start){
	int i;
	//��ʼ��"��־"����Ϊ 0
	for(i = 0; i < G->vexnum; i++){
		visited[i] = 0; 
	} 
	
	// �� ָ������ ���� 
	DFS(G, start);
	visited[start] = 1;
	// forѭ������ֹͼ�Ƿ���ͨͼ��һ�εݹ���ò���ȫ�������� 
	for(i = 0; i < G->vexnum; i++){
		if(visited[i] == 0){
			DFS(G, i);
		}
	} 
}

int main(){
	MGraph G;
	CreateUDG(&G);
	
	printf("\n\n������ȱ�����");
	int start = 0; 
	DFSTraverse(&G, start); 
	 
	return 0;
}	
