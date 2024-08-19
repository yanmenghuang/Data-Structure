
int visited[Max];

// i����ʾ��ʼ���㣬j����ʾҪ�ҵĶ��� 
void DFS(ALGraph G, int i, int j, bool &isok){
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




