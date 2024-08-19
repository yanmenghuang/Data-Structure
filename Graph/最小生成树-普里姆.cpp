#include <stdio.h>
#include <stdlib.h>
#define VertexMax 100 //��󶥵���Ϊ100
#define MaxInt 32767 //��ʾ�����������ʾ �� 

typedef char VertexType; //ÿ��������������Ϊ�ַ��� 

//�ڽӾ���ṹ�� 
typedef struct{
	//��Ŷ���Ԫ�ص�һά���� 
	VertexType Vertex[VertexMax];
	//�ڽӾ����ά���� 
	int AdjMatrix[VertexMax][VertexMax];
	//ͼ�Ķ������ͱ��� 
	int vexnum,arcnum;
}MGraph;

//��������ṹ��(��ѡ��̱�) 
typedef struct{
	//��ѡ��̱ߵ��ڽӵ� 
	VertexType adjvex;
	//��ѡ��̱ߵ�Ȩֵ 
	int lowcost;
	/*
	   lowcost = 0����ʾ ��������Ѿ����� U�����У��� �Ѿ����ɵ���С������������ 
	   �� lowcost ��Ϊ 0��������� U����
	   lowcost �м�¼���� V0 ����������Ĵ��� 
	
	  �� ��һ����õ�����ڽӱ� ���� �� V�����еĶ��㣬�� ����� �� lowcost�����е�ֵ���бȽ� 
	*/
}ShortEdge; // ShortEdge�����±� ��ʾ ������� 

//���� ����v ��һά���� Vertex[] �е��±꣬�������±�
int LocateVertex(MGraph *G, VertexType v){
	int i;
	for(i = 0; i < G->vexnum; i++){
		if(v == G->Vertex[i]){
			return i; 
		} 
	} 
	return -1;
}

//������������Undirected Network��
void CreateUDN(MGraph *G){
	int i, j;
	// 1.���붥�����ͱ���
	printf("�����붥������ͱ�����\n");
	printf("������ n = "); 
	scanf("%d", &G->vexnum);
	printf("��  �� e = "); 
	scanf("%d", &G->arcnum);
	printf("\n\n"); 
	
	// 2.���붥��Ԫ�� 
	printf("���붥��Ԫ��(����ո����)��");
	scanf("%s", &G->Vertex);
	
	printf("\n\n");
	
	// 3.�ڽӾ����ʼ��
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
			if(i == j){
				G->AdjMatrix[i][j] = 0;
			}
			else{
				G->AdjMatrix[i][j] = MaxInt;
			}
	    	
		}
	} 
	 
	// 4.�����ڽӾ���
	int n, m;
	VertexType v1, v2;
	// ���� v1��v2֮���Ȩֵ 
	int w;
	 
	printf("������ߵ���Ϣ��Ȩֵ(����A B 15)��\n");
	// forѭ�������� 
	for(i = 0; i < G->arcnum; i++){
		printf("������� %d ������Ϣ��Ȩֵ��",i+1);
		// ע��%c ǰ����Ҫ��ӿո���� 
	 	scanf(" %c %c %d", &v1,&v2,&w);
	 	
	 	//��ȡ v1��v2 ����Ӧ����Vertex�����е����� 
	 	n = LocateVertex(G, v1); 
	 	m = LocateVertex(G, v2); 
	 	// ����ߵ���Ϣ�Ƿ����������� 
	 	while(n == -1 || m == -1){
	 		printf("û�иñ���Ϣ!\n");
	 		printf("����������� %d ������Ϣ��Ȩֵ��", i+1);
	 		// ע��%c ǰ����Ҫ��ӿո���� 
	 		scanf(" %c %c %d", &v1, &v2, &w);
	 		n=LocateVertex(G, v1); 
	 		m=LocateVertex(G, v2); 
		} 
	 	// ���ڽӾ�����Ӧλ�ø���Ȩֵ 
		G->AdjMatrix[n][m]=w;
	   	G->AdjMatrix[m][n]=w;
    } 
}

// �������ͼ 
void print(MGraph G){
	int i,j;
	printf("\n-------------------------------");
	printf("\n �ڽӾ���\n\n"); 	
	
	printf("\t ");
	for(i = 0; i < G.vexnum; i++){
		printf("\t%c", G.Vertex[i]);
	}
	
	printf("\n");
		 
	for(i = 0; i < G.vexnum; i++){
   		printf("\t%c", G.Vertex[i]);
   	  	for(j = 0; j < G.vexnum; j++){
    		if(G.AdjMatrix[i][j] == MaxInt){
    			printf("\t��");
			}
			else{
				printf("\t%d", G.AdjMatrix[i][j]);
			}
    	}
      	printf("\n");
    }	 
}
 
//�����·���Ķ��� ���� lowcost�� Ѱ�� ��С���۵Ķ��㣩 
// ע�⣺��Ҫ�� lowcostֵ�Ѿ�Ϊ 0 �Ķ����ų��� 
int minimal(MGraph *G, ShortEdge *shortedge){
	int i, j;
	int min, locate;
	
	min = MaxInt;
	for(i = 0; i < G->vexnum; i++){
		// ������С ���� ������U���� 
		if(min > shortedge[i].lowcost && shortedge[i].lowcost != 0){
			min = shortedge[i].lowcost;
			// lowcost�����±� ��ʾ ������� 
			locate = i;
		}
	}
	// ���� Ŀǰ�ܵ������С���㣨�����±� ��ʾ ������� �� 
	return locate;
}

/*
	��� ��С������ ·�� 
	shortedge[5].adjvex = 0, shortedge[5].lowcost = 19
	��ʾ �� ����0 ���� ������̶���5������Ϊ19 
*/
void outputMST(MGraph *G, VertexType k, ShortEdge shortedge[]){
	//����ҵ������·��������·��Ȩֵ 
	printf("%c -> %c, weight = %d\n", shortedge[k].adjvex, G->Vertex[k], shortedge[k].lowcost);
}
 
// ��С������-����ķ�㷨 
void MiniSpanTree_Prim(MGraph *G, VertexType start){ 
	int i, j, k;
	ShortEdge shortedge[VertexMax];
	
	// 1.������ʼ��start 
	k = LocateVertex(G, start);
	
	// ��ʼ���������� shortedge���� �ӿ�ʼ���� �� ���ඥ��Ĵ��ۣ� 
	for(i = 0; i < G->vexnum; i++){
		// ��ʼ����start  ��   ����i 
		shortedge[i].adjvex = start;
		shortedge[i].lowcost = G->AdjMatrix[k][i];
	}
	// �� ���start ���뼯��U���Ѿ����ɵ� ������С�������� 
	shortedge[k].lowcost = 0; //lowcostΪ0��ʾ�ö�������U���� 
	
	// 2.���������� 
	//�Լ���U��ȥ�����·���Ķ��� 
	// �ܹ� vexnum �����㣬��ʼ���� �Ѿ������ˣ����ֻ��Ҫ���� vexnum - 1 ������ 
	for(i = 0; i < G->vexnum-1; i++){
		//�� �������·�� �Ķ��� 
		k = minimal(G, shortedge);
		//����ҵ������·��������·��Ȩֵ 
		outputMST(G, k, shortedge); 
	    
	    //���ҵ������·��������뼯��U�У�U������չ 
	    shortedge[k].lowcost = 0; 
	    
	    /* 
	        U�����м������½ڵ㣬ͨ�� �¼���ڵ� ���������ڵ㣬
		   ���ܳ����µ����·�����ʸ���shortedge����  
		*/
	    for(j = 0; j < G->vexnum; j++){ // ���� K���� ���������� 
			//�и���·������ʱ������shortedge����	 
	    	// �� ��һ����õĶ��� ���� �� V�����еĶ��㣬�� ����� �� lowcost�����е�ֵ���бȽ� 
	    	// G->AdjMatrix[k][j]���� ��һ����õĶ��� ���� �� V�����еĶ��� 
	    	if(G->AdjMatrix[k][j] < shortedge[j].lowcost){
	    		// ���ﶥ�� j ����̾��룬�� K �� j 
	    		shortedge[j].lowcost = G->AdjMatrix[k][j];
				// ���� K ���㣬���� j ����
	    		shortedge[j].adjvex = G->Vertex[k];
			}
		}
	} 
}

int main(){
	
	VertexType start;
	MGraph G;
	
	CreateUDN(&G);
	print(G); 
	
	while(true){
		printf("��������ʼ�㣺");
		// ע��%c ǰ����Ҫ��ӿո���� 
		scanf(" %c", &start);
		MiniSpanTree_Prim(&G, start);
		int flag;
		printf("\n�Ƿ�������в��ԣ���1���ǣ�0����\n");
		scanf("%d", &flag);
		if(flag == 0){
			break;
		}
	} 
	
	return 0;
}
