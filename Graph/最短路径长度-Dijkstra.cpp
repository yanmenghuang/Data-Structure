#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //��󶥵���Ϊ20
#define MaxInt 32767 //��ʾ�����������ʾ �� 

typedef int VertexType; //ÿ��������������Ϊ�ַ��� 

typedef struct{
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

void CreateDN(MGraph *G){
	int i,j;
	//1.���붥�����ͱ��� 
	printf("���붥������ͱ�����\n");
	printf("������ n="); 
	scanf("%d",&G->vexnum);
	printf("��  �� e="); 
	scanf("%d",&G->arcnum);

	//2.���붥��Ԫ�� 
	for(int i = 0; i < G->vexnum; i++){
		// �����±� ���� ����ֵ 
		G->Vertex[i] = i; 
		// printf("���붥��Ԫ�أ�");
		// scanf("%d",&G->Vertex[i]);
	}
	// printf("���붥��Ԫ��(����ո����)��");
	// scanf("%s",G->Vertex);
	printf("\n");
	//3.�����ʼ��
	for(i = 0; i < G->vexnum; i++){
		for(j = 0; j < G->vexnum; j++){
	    	G->AdjMatrix[i][j]=MaxInt;
		}
	}
	 
	//4.�����ڽӾ���
	int n,m;
	VertexType v1,v2;
	int w;//v1->v2��Ȩֵ 
	 
	printf("����·����·�����ȣ�\n");
	for(i=0;i<G->arcnum;i++){
		printf("�����%d��·����Ϣ��",i+1);
	 	scanf("%d %d %d",&v1,&v2,&w);
	 	n=LocateVex(G,v1); //��ȡv1����Ӧ����Vertex�����е����� 
	 	m=LocateVex(G,v2); //��ȡv2����Ӧ����Vertex�����е�����
	 	
	 	// ����ߵ���Ϣ�Ƿ����������� 
	 	while(n == -1 || m == -1){
	 		printf("NO This Vertex!\n");
	 		printf("������ �����%d������Ϣ��Ȩֵ��",i+1);
	 		scanf("%d %d %d",&v1,&v2,&w);
	 		n=LocateVex(G,v1); 
	 		m=LocateVex(G,v2); 
		} 
		// ��Ȩֵ 
	    G->AdjMatrix[n][m]=w;
	}
}

// ��� �ڽӾ��� 
void print(MGraph G){
	int i,j;
	printf("\n-------------------------------");
	printf("\n �ڽӾ���\n\n"); 	
	printf("\t ");
	for(i=0;i<G.vexnum;i++){
		printf("\t%d",G.Vertex[i]);
	}
	printf("\n");
	for(i=0;i<G.vexnum;i++){
		printf("\t%d",G.Vertex[i]);
	  	for(j=0;j<G.vexnum;j++){
	    	if(G.AdjMatrix[i][j]==MaxInt){
	    		printf("\t��");
			}
	 	    else{
	 	    	printf("\t%d",G.AdjMatrix[i][j]);
			}
		}
    	printf("\n");
	} 
}

void displayPath(int dist[],int path[],MGraph *G,VertexType start){
	int i,k,j=0;
	int temp[VertexMax];//��ʱ���� 
	// VertexType target;//Ŀ��ص� 
	int loc = 0; 
	
	/*
	printf("\n-----------------------------------------------\n");
	printf("���չʾ��\n");
	printf("\n\n");
	//��ӡdist���� 
	printf("\tdist[i]:\n\t");
	for(i=0;i<G->vexnum;i++)
	printf("\t%d",i);
	printf("\n\t"); 
	for(i=0;i<G->vexnum;i++){
    	printf("\t%d",dist[i]);
	}
	printf("\n");
	
	//��ӡpath���� 
	printf("\n\tpath[i]:\n\t");
	for(i=0;i<G->vexnum;i++)
	printf("\t%d",i);
	printf("\n\t"); 
	for(i = 0; i < G->vexnum; i++){
    	printf("\t%d",path[i]);
	}
	
	*/
    printf("\n\n"); 
	 //���·�� 
	printf("���·��:\n\n"); 
	for(i = 0; i < G->vexnum; i++){
		// ��ʱ�����ʼ�� 
		for(k = 0; k < VertexMax; k++){
	    	temp[k]=-1;
		}
		
		loc = i;
		j = -1;
		while(loc != -1){
    		temp[++j] = loc;
    		loc = path[loc];
		}
		
		if(j == 0 && G->Vertex[temp[j]] == start){
			printf("\t");
			printf("%d -> %d:%dΪ��ʼ��!",start,G->Vertex[i],G->Vertex[temp[j]]);
		}
		else if(j == 0 && G->Vertex[temp[j]] != start){
			printf("\t");
			printf("%d -> %d:%d���ɴ�%d",start,G->Vertex[i],start,G->Vertex[temp[j]]);
		}
		else{
			printf("\t");
			printf("%d -> %d:",start,G->Vertex[i]);
			for(j ;j >= 0; j--){
				printf("%d ", G->Vertex[temp[j]]);
			}
			printf("(��·������:%d)", dist[i]);
		}
	    
	 	printf("\n\n");
	}
}

int FindMinDist(int dist[], int s[], int vexnum){
	int i;
	int loc;
	int min = MaxInt+1;
	for(i = 0; i < vexnum; i++){
		//ֻ��s[i]=0�Ķ�����в��ң������� ������ S�����еĶ��㣩 
		if(s[i] == 0){
			if(dist[i] < min){
				min = dist[i];
				loc = i;
			}
		}
	}
	return loc;//����dist����СԪ�ص��±꣬�� �ܹ�����ĵ�ǰ��С���� 
}

void ShortestPath_Dijkstra(MGraph *G, VertexType start){
	int i,j,num;
	int loc;
	int min;
	
	int dist[VertexMax];//��� ·������ ���� 
	// dist[i]����ʾ��ǰ���ҵ��Ĵ� ʼ��V ���յ�Vi �� ���·������ 
	
	// path���� ��¼������һ����������� 
	int path[VertexMax];//��� ·�� ���� 
	// path[i] ��һ���ַ�������ʾ��ǰ���ҵ��� ����ʼ�� ���յ�Vi�����·��
	// ��̬Ϊ���� ��V �� Vi�л����� path[i]Ϊ0�������� path[i] = 1 
	// path�����±��ʾ Ŀ��ڵ����  path����ֵ��ʾ Դ��
	// ��  p[3] = 0  ��ʾ �ӽڵ�0 �� �ڵ�3
	 
	int s[VertexMax];//������S��1����ö����Ѵ������ڼ���S��0����ö���δ���������ڼ���S�����ڼ���V-S�� 
	// ��� Դ�� �� �Ѿ����ɵ��յ㣬���̬Ϊ ֻ��һ��Դ��V 
	
	//1.��ʼ��dist��path���� 
	loc=LocateVex(G,start);//��ȡԴ����±�λ�� 
	for(i = 0; i < G->vexnum; i++){
		// dist[i] = ����start �� Vi �ľ��� 
		dist[i] = G->AdjMatrix[loc][i];
		
		if(dist[i]!=MaxInt){
			// ����start �� ����Vi �бߣ�path[i] ���� Դ����� 
			path[i] = loc;
		}
		else{
			// �ޱ� 
			path[i]=-1;
		}	  
	} 
    
    //2.��ʼ��S���飨s���飺������S��1�����Ԫ�����ڼ���S(�Ѵ���Ķ���)��0��Ԫ�ز����ڼ���S(δ����Ķ���)�� 
    for(i = 0; i < G->vexnum; i++){
		s[i] = 0;
	} 
	s[loc] = 1; //������ʼ��(Դ��)�Դ������ 
	num = 1;
	
	//3.�������num < ͼ�Ķ������ 
	while(num < G->vexnum){
		//��dist�����в������Ӧs[i]=0����δ�������СֵԪ�� 
		// �� ��ǰ�ܹ���������·���Ķ��� 
		min = FindMinDist(dist,s,G->vexnum);
		s[min] = 1;//���ҵ�����̱�����Ӧ�ĵĶ�����뼯��S
		
		//�����µĶ���󣬸���dist��path���� 
		// �ڼ����¶���󣬿����Ƿ� ͨ��������¶��� �������Ķ����и�С�ľ��� 
		for(i = 0; i < G->vexnum; i++){
			// s[i] == 0������ i ������ U���� 
			// dist[i]����ŵ��� 0 �� i ��·������ 
			// dist[min]��0 �� �ܵ���ǰ������ ��С·������	 
			// G->AdjMatrix[min][i]) ����С���� �� i ��·������ 
			if((s[i] == 0) && (dist[i] > dist[min] + G->AdjMatrix[min][i])){
				// ���� dist��С���� 
				dist[i] = dist[min] + G->AdjMatrix[min][i];
				// ���� path·�� ���� 
				path[i] = min;// min -> i��ͨ�� �ڵ�min ���� �ڵ�i  
			}
		}
	    num++;	
	} 
	for(int i = 0; i < G->vexnum; i++){
		printf("%d	", path[i]);
	}
	printf("\n");
	for(int i = 0; i < G->vexnum; i++){
		printf("%d	", dist[i]);
	}
    displayPath(dist, path, G, start);//չʾdist���顢path���鼰���·�� 
} 

int main() 
{
	MGraph G;
	VertexType start;
	
	CreateDN(&G);
	print(G); 
	
	printf("������ʼ�㣺"); 
	scanf(" %d",&start);
	printf("\n");
	ShortestPath_Dijkstra(&G,start);

	return 0;
}

