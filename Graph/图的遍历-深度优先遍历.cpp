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

int LocateVex(MGraph *G,VertexType v)//����Ԫ��v��һά���� Vertex[] �е��±꣬�������±� 
{
	int i;
	
	for(i = 0; i < G->vexnum; i++){
		if(v == G->Vertex[i]){
			return i; 
		} 
	} 
	 
	printf("No Such Vertex!\n");
	return -1;
}

//����ͼ
void CreateUDG(MGraph *G){
	int i,j;

	printf("���붥������ͱ�����\n");
	printf("������ n="); 
	scanf("%d",&G->vexnum);
	printf("��  �� e="); 
	scanf("%d",&G->arcnum);
	printf("\n"); 
	
	for(i = 0; i < G->vexnum; i++){
		G->Vertex[i] = i + 1;
	}
	
	for(i=0;i<G->vexnum;i++){
		for(j=0;j<G->vexnum;j++){
	    	G->AdjMatrix[i][j]=0;
		}
	}
	int n,m;
	VertexType v1,v2;
	 
	printf("������ߵ���Ϣ��\n");
	// forѭ�������� 
	for(i=0;i<G->arcnum;i++){
		printf("�����%d������Ϣ��Ȩֵ��",i+1);
	 	scanf("%d %d",&v1,&v2);
	 	
	 	n=LocateVex(G,v1); //��ȡv1����Ӧ����Vertex�����е����� 
	 	m=LocateVex(G,v2); //��ȡv2����Ӧ����Vertex�����е�����
	 	// ����ߵ���Ϣ�Ƿ����������� 
	 	while(n == -1 || m == -1){
	 		printf("NO This Vertex!\n");
	 		printf("������ �����%d������Ϣ��Ȩֵ��",i+1);
	 		scanf("%d %d",&v1,&v2);
	 		n=LocateVex(G,v1); 
	 		m=LocateVex(G,v2); 
		} 
	 	
		G->AdjMatrix[n][m]=1;
	   	G->AdjMatrix[m][n]=1;//���������˴���ͬ 
     } 
}

void print(MGraph G){
	int i,j;
	printf("\n-------------------------------");
	printf("\n �ڽӾ���\n\n"); 	

	printf("\t ");
    for(i=0;i<G.vexnum;i++){
    	printf("  %d",G.Vertex[i]);
	}
	printf("\n");
		 
	for(i=0;i<G.vexnum;i++){
	   	printf("\t%d",G.Vertex[i]);
	   	for(j=0;j<G.vexnum;j++){
	 	    printf("  %d",G.AdjMatrix[i][j]);
	    }
	        printf("\n");
	}
}


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
	for(i=0;i<G->vexnum;i++){
		visited[i]=0; 
	} 
	
	DFS(G,start);
	visited[start] = 1;
	// forѭ������ֹͼ�Ƿ���ͨͼ��һ�εݹ���ò���ȫ�������� 
	
	for(i=0;i<G->vexnum;i++){
		if(visited[i]==0){
			DFS(G,i);
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
	

