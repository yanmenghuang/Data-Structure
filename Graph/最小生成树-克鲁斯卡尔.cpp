#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //��󶥵���Ϊ20

typedef char VertexType;

// ���� �߼����� �洢ͼ�еı� 
typedef struct{
	VertexType begin;
	VertexType end;
	// ���ϵ�Ȩֵ 
	int weight;
}Edge;//�߼����� edge[]�ĵ�Ԫ 

typedef struct{
	//�������� 
	VertexType Vertex[VertexMax];
	//�߼����� 
	Edge edge[VertexMax];
	//������ 
	int vexnum;
	//���� 
	int edgenum;
}EdgeGraph;

void CreateEdgeGraph(EdgeGraph *E){
	int i;
	// 1.���붥�����ͱ���
	printf("�����붥�����ͱ���:\n");
	printf("������ n = "); 
	scanf("%d", &E->vexnum);
	printf("��  �� e = "); 
	scanf("%d", &E->edgenum);
	printf("\n"); 
	
	// 2.���붥��Ԫ�� 
	printf("���붥��(����ո����):"); 
	scanf("%s", &E->Vertex);
	printf("\n\n");
	
	printf("�������Ϣ��Ȩֵ(�磺A B 15):\n");
	for(i = 0; i < E->edgenum; i++){
		printf("������� %d �ߵ���Ϣ:", i+1);
		scanf(" %c %c %d", &E->edge[i].begin, &E->edge[i].end, &E->edge[i].weight);
	}	
}

void print(EdgeGraph *E){
	int i;
	
	printf("-----------------------------------\n"); 
	printf(" ��������Vertex:");
	for(i = 0; i < E->vexnum; i++){
		printf("%c ", E->Vertex[i]);
	}
	printf("\n\n");
	
	printf(" �߼�����edge:\n\n");
	printf("\t\tBegin	End	Weight\n");
	for(i = 0; i < E->edgenum; i++){
		printf("\tedge[%d]	%c	%c	%d\n", i, E->edge[i].begin, E->edge[i].end,E->edge[i].weight);
	}
	printf("-----------------------------------\n");
}

int partition(EdgeGraph *E, int low, int high){
	Edge pivot = E->edge[low];

	while(low < high){
		while(low < high && pivot.weight <= E->edge[high].weight){
			high--;
		}
		E->edge[low] = E->edge[high];
		
		while(low < high && E->edge[low].weight <= pivot.weight){
			low++;
		}
		E->edge[high] = E->edge[low];
	}
	E->edge[low] = pivot;
	// ���� �м�λ�� 
	return low;
}

// �� ͼ�еı� ��С����������� (��������)
void quickSort(EdgeGraph *E, int low, int high){
	// �ݹ�������� 
	if(low < high){
		// ���� 
		int pos = partition(E, low, high);
	
		quickSort(E, low, pos - 1);
		quickSort(E, pos + 1, high);
	}
} 

//����Ԫ��v��һά���� Vertex[] �е��±꣬�������±� 
int LocateVertex(EdgeGraph *E, VertexType v){
	int i;
	for(i = 0; i < E->vexnum; i++){
		if(v == E->Vertex[i]){
			return i; 
		} 
	}
	printf("No Such Vertex!\n");
	return -1;
}

// ���� v�������Vertex�����е��±� 
int FindRoot(int v,int parent[]){
	//parent=-1��ʾû��˫�ף���û�и��ڵ� 
	while(parent[v] != -1){
		//������Ҹ��ڵ� 
		v = parent[v];
	}
	//���ҵ��ĸ��ڵ㷵�أ���û�и��ڵ㣬�������� 
	return v;
}

void outputMST(EdgeGraph *E, int i){
	printf("%c �� %c, w = %d\n", E->edge[i].begin, E->edge[i].end, E->edge[i].weight);//����˱� 
}

// ��С������-��³˹�����㷨�㷨 
void MiniSpanTree_Kruskal(EdgeGraph *E){
	int i;
	//���ɱ߼��������� num = ������-1 ʱ����С������������� 
	int num;
	int root1, root2; 
	int LocateV1, LocateV2; 
	//���ڲ��Ҷ����˫�ף��ж�����������Ƿ��й�ͬ��˫�ף����ж��������Ƿ��ɻ� 
	int parent[VertexMax];
	
	//1.��Ȩֵ��С�������� 
	printf("����ǰ�ı߼����飺\n");
	print(E); 
	quickSort(E, 0, E->edgenum -1);
	printf("�����ı߼����飺\n");
	print(E);
	
	//2.��ʼ��parent���� 
	for(i = 0; i < E->vexnum; i++){
		// �� ͼ�����ж��� ���� һ��ֻ�и������� 
		parent[i] = -1;
	}
	
	printf("\n ��С������(Kruskal):\n\n");
	//3. forѭ�������� edge������ 
	for(num = 0, i = 0; i < E->edgenum; i++){
		LocateV1 = LocateVertex(E, E->edge[i].begin);
		LocateV2 = LocateVertex(E, E->edge[i].end);
		// �ҵ� �����������ĸ���� 
		root1 = FindRoot(LocateV1, parent);
		root2 = FindRoot(LocateV2, parent);
	
		// ������ɻ���������С�������й����˱�
		// ����㲻��� �� �ڲ�ͬ����ͨ������ 
		if(root1 != root2){
			// ����ñ� 
			outputMST(E, i);
			//�ϲ����������� root1 ��Ϊ ����㣬�� root2 ��˫��Ϊ root1 
			parent[root2] = root1;
			// ��С���������� + 1 
			num++;
			
			//��num=������-1��������������ϣ���ǰ���� 
			if(num == E->vexnum-1){
				return;
			}
		} 
	}
}

int main(){
	EdgeGraph E;
	CreateEdgeGraph(&E);
	MiniSpanTree_Kruskal(&E);
	
	return 0;
}
