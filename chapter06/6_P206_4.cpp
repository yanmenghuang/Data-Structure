
// �ڽӱ�洢���
// �߱�Ľ�� 
typedef struct Arcnode{
	// ��ǰ��ָ�򶥵��λ��
	int adjvex;
	// ָ����һ������ָ��
	struct Arcnode *next; 
}Arcnode; 

// �������
typedef struct Vnode{
	// ������Ϣ
	char data;
	// ָ���һ�� �����ö��㻡��ָ�� 
	// ע�⣺ָ������Ϊ Arcnode���� 
	Arcnode *first;
}Vnode, AdjList[10]; 

// ��ϵ��ڽӱ�
typedef struct{
	// �ڽӱ�
	AdjList v; 
	// ������ �� ���� 
	int vnum, arcnum;
}ALGraph; 
 

void Convert(ALGraph &G, int arc[N][N]){
	// ����ȡ�� 
	Arcnode *p; 
	
	// forѭ�� ���� ÿ���������Ϊͷ �ı���������� 
	for(int i = 0; i < n; i++){
		// ע��д�� 
		// ȡ���� i �ĵ�һ���� 
		p = (G->v.first);
		
		// whileѭ�� �����ö������Ϊͷ�ı����� ������� 
		while(p != NULL){
			// �� 1 
			arcs[i][p->adjvex] = 1;
			// ָ����һ����� ��ȡ��һ����
			p = p->next 
			
		}
	} 
}


