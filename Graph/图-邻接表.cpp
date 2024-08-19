#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //��󶥵���Ϊ20
#define MaxInt 32767 //��ʾ�����������ʾ ��

#define MVNum 100
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
	ArcNode *firstarc;	//����ĵ�һ�ڽӵ�
}VNode,AdjList[MVNum];	//AdjList��ʾ�ڽӱ�����

//�ڽӱ�
typedef struct{
	// AdjList[MVNum]���������� 
	AdjList vertices;	//һά����vertices
	int vexnum,arcnum;	//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

//����Ԫ��v��һά���� Vertex[] �е��±꣬�������±� 
int LocateVex(ALGraph *G, VertexType v){
	int i;
	for(i = 0; i < G->vexnum; i++){
		if(v == G->vertices[i].data){
			return i; 
		} 
	} 
	printf("No Such Vertex!\n");
	return -1;
}


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
		n = LocateVex(G,v1);	//ȷ������v1��ͼG�е�λ�ã�һά�����±꣩
		m = LocateVex(G,v2);	//ȷ������v2��ͼG�е�λ�ã�һά�����±꣩
		
		// ����ߵ���Ϣ�Ƿ����������� 
	 	while(n == -1 || m == -1){
	 		printf("NO This Vertex!\n");
	 		printf("������ �����%d������Ϣ��Ȩֵ��",i+1);
	 		scanf("%d %d %d",&v1,&v2,&weight);
	 		n=LocateVex(G,v1); 
	 		m=LocateVex(G,v2); 
		} 
		
		ArcNode* p1 = (ArcNode*) malloc(sizeof(ArcNode));	//�����½��(ָ��p1ָ��ý�㣬��p1����ý��)
		p1->adjvex = m;		//�ڽӵ���һά�����е��±�ֵ��ֵ���ý��
		p1->weight = weight;
		// ���� ����ͷ�巨 
		p1->nextarc = G->vertices[n].firstarc;	
		G->vertices[n].firstarc = p1;	
		
		ArcNode* p2 = (ArcNode*) malloc(sizeof(ArcNode));	//�����½��(ָ��p2ָ��ý�㣬��p2����ý��)
		p2->adjvex = n;		//�ڽӵ���һά�����е��±�ֵ��ֵ���ý��
		p2->weight = weight;
		
		p2->nextarc = G->vertices[m].firstarc;
		G->vertices[m].firstarc = p2;	
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

int main(){
	
	ALGraph LG;

	CreateUDG(&LG);

	printLG(LG);
	
	return 0;
}


