#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 
#define MaxInt 32767 

typedef int VertexType;

typedef struct{
	VertexType Vertex[VertexMax];//��Ŷ���Ԫ�ص�һά���� 
	int AdjMatrix[VertexMax][VertexMax];//�ڽӾ����ά���� 
	int vexnum, arcnum; //ͼ�Ķ������ͱ���  
}MGraph;

int FindMinDist(int dist[], int s[], int vexnum) {
	int i;
	int locate;
	int min = MaxInt+1;
	for(i = 0; i < vexnum; i++){
		//ֻ��s[i]=0�Ķ�����в��ң������� ������ S�����еĶ��㣩 
		if(s[i] == 0){
			if(dist[i] < min){
				min = dist[i];
				locate = i;
			}
		}
	}
	return locate;//����dist����СԪ�ص��±꣬�� �ܹ�����ĵ�ǰ��С���� 
}

void ShortestPath_Dijkstra(MGraph *G, VertexType start){
	int i,j,num;
	int locate;
	int min;
	//��� ·������ ���� 
	int dist[VertexMax];
	// path���� ��¼������һ����������� 
	int path[VertexMax];//��� ·�� ���� 
	// ��� Դ�� �� �Ѿ����ɵ��յ㣬���̬Ϊ ֻ��һ��Դ��V 
	int s[VertexMax];
	
	//1.��ʼ��dist��path���� 
	locate = LocateVex(G,start);//��ȡԴ����±�λ�� 
	for(i = 0; i < G->vexnum; i++){
		// dist[i] = ����start �� Vi �ľ��� 
		dist[i] = G->AdjMatrix[loc][i];
		
		if(dist[i] != MaxInt){
			// ����start �� ����Vi �бߣ�path[i] ���� Դ����� 
			path[i] = locate;
		}
		else{
			// �ޱ� 
			path[i] = -1;
		}	  
	} 
    
    //2.��ʼ��S����
    for(i = 0; i < G->vexnum; i++){
		s[i] = 0;
	} 
	s[locate] = 1; //������ʼ��(Դ��)�Դ������ 
	num = 1; // �Ѵ�������� 
	
	//3.�������num < ͼ�Ķ������ 
	while(num < G->vexnum){
	
		min = FindMinDist(dist, s, G->vexnum);
		s[min] = 1;
		 
		for(i = 0; i < G->vexnum; i++){
			if((s[i] == 0) && (dist[i] > dist[min] + G->AdjMatrix[min][i])){
				// ���� dist��С���� 
				dist[i] = dist[min] + G->AdjMatrix[min][i];
				// ���� path·�� ���� 
				path[i] = min;// min -> i��ͨ�� �ڵ�min ���� �ڵ�i  
			}
		}
	    num++; // �Ѵ������� + 1 
	} 
	//չʾdist���顢path���鼰���·��
    displayPath(dist, path, G, start); 
} 

void displayPath(int dist[],int path[],MGraph *G,VertexType start){
	int i,k,j=0;
	int temp[VertexMax];//��ʱ���� 
	int loc = 0; 

	printf("���·��:\n\n"); 
	// forѭ��һ�Σ�ÿһ���ҵ��� ��ʼ���� �� ���� i ��·�� 
	for(i = 0; i < G->vexnum; i++){
		// ÿһ�� for ѭ������ʱ�����ʼ�� 
		for(k = 0; k < VertexMax; k++){
	    	temp[k] = -1;
		}
		
		loc = i;
		j = -1;
		// path[start] = -1����ʼ����� pathֵΪ - 1 
		while(loc != -1){
    		temp[++j] = loc;
    		loc = path[loc];
		}
		
		if(j == 0 && temp[j] == start){
			printf("%dΪ��ʼ��!", temp[j]);
		}
		else if(j == 0 && temp[j] != start){
			printf("%d ���ɴ� %d", start, temp[j]);
		}
		else{
			for(j ;j >= 0; j--){
				printf("%d ", temp[j]);
			}
			printf("(��·������:%d)", dist[i]);
		}
	 	printf("\n\n");
	}
}
 
int main(){
	MGraph G;
	VertexType start;
	CreateDN(&G);
	
	printf("������ʼ�㣺"); 
	scanf(" %d", &start);
	ShortestPath_Dijkstra(&G, start);

	return 0;
}

