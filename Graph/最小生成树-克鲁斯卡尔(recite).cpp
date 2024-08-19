#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //��󶥵���Ϊ20

typedef int VertexType; 

// ���� �߼����� �洢ͼ�еı� 
typedef struct{
	VertexType begin;
	VertexType end;
	// ���ϵ�Ȩֵ 
	int weight;
}Edge;//�߼����� edge[]�ĵ�Ԫ 

typedef struct{
	VertexType Vertex[VertexMax];//�������� 
	Edge edge[VertexMax];//�߼����� 
	int vexnum;//������ 
	int edgenum;//���� 
}EdgeGraph;  // ͼ�Ľṹ�� 

// ����ͼ 
void CreateEdgeGraph(EdgeGraph *E)

// �� ͼ�еı� ��С�������� 
int partition(EdgeGraph *E, int low, int high){
	Edge pivot = E->edge[low];
	// int pivot = a[low]; 

	while(low < high){
		while(low < high && pivot.weight <= E->edge[high].weight){
			high--;
		}
		E->edge[low] = E->edge[high];
		// a[low] = a[high];
		
		while(low < high && E->edge[low].weight <= pivot.weight){
			low++;
		}
		E->edge[high] = E->edge[low];
		// a[high] = a[low];
	}
	E->edge[low] = pivot;
	// a[low] = pivot;
	// ���� �м�λ�� 
	return low;
}

void QuickSort(EdgeGraph *E, int low, int high){
	// �ݹ�������� 
	if(low < high){
		// ���� 
		int pos = partition(E, low, high);
	
		quickSort(E, low, pos - 1);
		quickSort(E, pos + 1, high);
	}
} 

//t���յ��ǽ����Vertex�����е��±� 
int FindRoot(int t, int parent[]){
	//parent=-1��ʾû��˫�ף���û�и��ڵ� 
	while(parent[t] != -1){
		//������Ҹ��ڵ� 
		t = parent[t];
	}
	// while ѭ������������parent[t] == -1��tû��˫�׽ڵ㣬t���Ǹ��ڵ� 
	//���ҵ��ĸ��ڵ㷵�أ���û�и��ڵ㷵������ 
	return t;
}

void outputMST(EdgeGraph *E, int i){
	printf("\t\t%d-%d, weight = %d\n", E->edge[i].begin, E->edge[i].end, E->edge[i].weight);//����˱� 
}

void MiniSpanTree_Kruskal(EdgeGraph *E){
	int i;
	int num;//���ɱ߼���������num=������-1 �ʹ�����С������������� 
	int root1, root2; 
	int parent[VertexMax];//���ڲ��Ҷ����˫�ף��ж�����������Ƿ��й�ͬ��˫�ף����ж��������Ƿ��ɻ� 
	
	//1.��Ȩֵ��С�������� 
	QuickSort(E, 0, E->vexnum - 1);
	print(E);
	
	//2.��ʼ��parent���� 
	for(i = 0; i < E->vexnum; i++){
		// ��Ϊ ͼ�����ж��� ���� һ��ֻ�и������� 
		parent[i] = -1;
	}
	
	printf("\n ��С������(Kruskal):\n\n");
	//3. forѭ�������� edge������ 
	for(num = 0,i = 0; i < E->edgenum; i++){
		// �ҵ� �����������ĸ���� 
		root1 = FindRoot(E->edge[i].begin, parent);
		root2 = FindRoot(E->edge[i].end, parent);
	
		//������ɻ���������С�������й����˱�
		// ����㲻��� �� �ڲ�ͬ����ͨ������ 
		if(root1 != root2){
			outputMST(E, i); //����˱� 
			//�ϲ������� �� root1 ��Ϊ �����
			parent[root2] = root1; // root2 ��˫��Ϊ root1 
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

