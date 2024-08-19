#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 //��󶥵���Ϊ20
#define MaxInt 32767 //��ʾ�����������ʾ ��

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
	// ָ������Ϊ ArcNode�ṹ������ 
	ArcNode *firstarc;	//����ĵ�һ�ڽӵ�
}VNode,AdjList[VertexMax];	//AdjList��ʾ�ڽӱ�����

//�ڽӱ�
typedef struct{
	// AdjList[MVNum]���������ͣ������ÿһ��Ԫ��Ϊ VNode���� 
	AdjList vertices;	//һά����vertices
	int vexnum,arcnum;	//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

// ���� ����Ϊ 0 �Ķ������
int Count_Out(ALGraph G){
	int count = 0;
	for(int i = 0; i < G.vexnum; i++){
		ArcNode* p = G.vertices[i].firstarc;
		if(p == NULL){
			printf("���� %d �ĳ���Ϊ 0\n", i);
			count++;
			break;
		}
	}
	return count;
}

// ���� ���Ϊ 0 �Ķ������
int Count_In(ALGraph G){
	int i, j;
	int count = 0;
	bool flag;
	for(i = 0; i < G.vexnum; i++){
		flag = true;
		for(j = 0; j < G.vexnum; j++){
			// G.vertices[j]��ע�⣺�� j ���� i 
			ArcNode* p = G.vertices[j].firstarc;
			while(p){
				if(p->adjvex == i){
					flag = false;
					break;
				}
				p = p->nextarc;
			}
			if(!flag){
				break;
			}
		}
		if(flag){
			printf("���� %d ���Ϊ 0\n", i);
			count++;
		}
	}
	return count;
}

int main(){
	
	ALGraph LG;
	CreateUDG(&LG);
	
	int count_out = Count_Out(LG);
	int count_in = Count_In(LG);
	
	printf("����Ϊ 0 �Ķ��������%d", count_out);
	printf("���Ϊ 0 �Ķ��������%d", count_in);
	
	return 0;
} 
