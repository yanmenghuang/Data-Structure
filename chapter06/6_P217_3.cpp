// �ǵݹ� DFS ����ͼ 

void DFS(AGraph &G, int v){
	//��ʼ��ջ 
	stack S; 
	InitStack(S);
	
	bool visited[G.vexnum + 1];
	for(int i = 0; i < G.vexnum; i++){
		visited[i] = false;
	}
	
	// ���� v ѹ��ջ�У����� visited ���� 
	Push(S, v);
	visited[v] = true;
	
	while(!isEmpty(S)){
		// ��ջ������  k �����ջ��� 
		k = Pop(S, v);
		
		// ���ʸý�㣬���ʵ�˳�����DFS˳�� 
		visit(k);
		/*
		    w = NextNeighbor(G, v, w);
		    ���س� w ���ⶥ�� v ����һ���ڽӵ�Ķ��� 
		*/
		// forѭ������ k ������ δѹ���ջ �������ڽӽ�� ��ջ 
		for(w = FirstNeighbor(G, k); w >= 0; w = NextNeighbor(G, k, w)){
			// �жϵ�ǰ��� w �Ƿ� �����ջ 
			if(!visited[w]){
				Push(S, w);
				visited[w] = true;
			}
		} 
	}
}





