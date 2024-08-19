#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //��󶥵���Ϊ20
#define MaxInt 32767 //��ʾ�����������ʾ ��

typedef int VertexType;

// �ڽӾ��� 
typedef struct{
	VertexType Vertex[VertexMax];//��Ŷ���Ԫ�ص�һά���� 
	int AdjMatrix[VertexMax][VertexMax];//�ڽӾ����ά���� 
	int vexnum,arcnum;//ͼ�Ķ������ͱ���  
}MGraph;

// ���� ����Ϊ 0 �Ķ������ 
int Count_Out(MGraph G){
	int count = 0;
	bool flag;
	for(int i = 0; i < G.vexnum; i++){
		flag = true;
		for(int j = 0; j < G.vexnum; j++){
			if(G.AdjMatrix[i][j] != MaxInt){
				flag = false;
				break;
			}
		}
		if(flag){
			printf("����Ϊ 0 �Ķ��㣺%d	", i);
			count++;
		}
	}
	return count;
}

// ���� ���Ϊ 0 �Ķ������
int Count_In(MGraph G){
	int count = 0;
	int flag;
	for(int i = 0; i < G.vexnum; i++){
		flag = true;
		for(int j = 0; j < G.vexnum; j++){
			if(G.AdjMatrix[j][i] != MaxInt){
				flag = false;
			}
		}
		if(flag){
			printf("���Ϊ 0 �Ķ��㣺%d	", i);
			count++;
		}
	}
	return count;
}

int main(){
	
	MGraph G;
	CreateDN(&G);
	
	int count_out = Count_Out(G);
	int count_in = Count_In(G);
	printf("����Ϊ 0 �Ķ��������%d\n", count_out);
	printf("���Ϊ 0 �Ķ��������%d\n", count_in);

	return 0;
}
