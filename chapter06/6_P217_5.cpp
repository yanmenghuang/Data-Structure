
int visited[Max];

// i����ʾ��ʼ���㣬j����ʾҪ�ҵĶ��� 
void DFS(ALGraph G, int i, 
// u����ʼ���� v���յ��� d��·������ 
void FindPath(ALGraph *G, int u, int v, int []path, int &d){
	// ��ӵ�ǰ��㵽·���У�����·������ + 1���ټ����� 
	d++;
	path[d] = u;
	visited[u] = 1;
	
	// ����õ�Ϊ·���յ㣬��� 
	if(u == v){
		for(int i = 0; i < path.length; i++){
			printf("%d", path[i]);
		}
	}
	// p ָ�� u���ڽӵ㣬����һ�����ڵ� 
	ArcNode *p = G->adjList[u].firstarc;
    
	// ����ȥ���� ���ڵ����һ���ڽӵ㣬���ȥ���� 
	while(p != NULL){
		// ��ȡ ��ǰ���ڽӵ�Ļ� ��ָ�򶥵��λ�� 
		int w = p->adjex;
		// wΪ�����ʹ���ֱ�ӵݹ���� 
		if(visited[w] == 0){
			FindPath(G, w, v, path, d);
		}
		// ���� p ���� 
		p = p->nextarc;
	}
	// ���ܵ�ǰ�ݹ�û���ҵ�����Ҫ���ݣ�ʹ�õ��������ʹ�� 
	visited[u] = 0;
}int j, bool &isok){
	if(i == j){
		isok = true;
		return;
	}
	
	visited[i] = 1;
	
	for(int p=FirstNeighbor(G, i); p >= 0; p = NextNeighbor(G, i, p)){
		// ���û���ҵ� j�� ���� �õ�û�з��ʹ�������DFS����
		if(!visited[p] && !isok){
			DFS(G, p, j, isok);
		} 
	}
}

int BFS(ALGraph G, int i, int j){
	queue Q;
	InitQueue(Q);
	
	EnQueue(Q, i);
	
	while(!isEmpty(Q)){
		// ���� �� ��������Ԫ�� 
		DeQueue(Q, u)
		visited[u] = 1;
		
		if(u == j){
			return 1;
		}
		
		for(int p = FirstNeighbor(G, i); p >= 0; p = NextNeighbor(G, i, p)){
			// �ٴ��ж��Ƿ�Ϊ j ����
			// �� ֱ�ӷ��� 
			if(p == j){
				return 1;
			}
			// ���� ���ڽӵ���� 
			if(!visited[p]){
				EnQueue(Q, p);
				visited[p] = 1;
			}
		}
	}
	// ��ȱ�����ͼ����û���ҵ� j ���� 
	return 0;
}




