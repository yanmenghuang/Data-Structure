
// �洢ʱ������ 
int finishtime[Max];
// ���ʵı������ 
bool visited[Max];
void DFS(Graph G, int v){
	// ���ʵ�ǰ���� 
	visiited[v] = true; 
	visit(v);
	
	for(w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)){
		if(!visited[w]){
			DFS(G, w);
		}
	}
	
	// �ݹ���󣬿�ʼ ����
	time++; 
	finishtime[v] = time;
	
	
}

void DFSTraverse(Graph G){
	for(int i = 0; i < G.vexnum; i++){
		visited[i] = false;
	}
	
	// ��ʼ��ʱ��
	time = 0;
	// DFSÿ��û�б����ʹ��Ķ���
	for(int v = 0; v < G.vexnum; i++){
		if(!visited[v]){
			DFS(G, v);
		} 
	} 
}
