
void DFS(Graph &G, int v, int &Vnum, int &Enum, visited[]){
	visited[v] = true; // ���ʹ� 
	Vnum++; // ������ + 1
	
	int w = FirstNeighbor(G, v);
	// w ��Ϊ -1��˵�������ڱ� 
	while(w != -1){
		// ��һ���ڽӽ����� ���ڱ�
		Enum++; // �� +1 
		// �ж� w �Ƿ���ʹ� 
		if(!visited[w]){
			DFS(G, w, Vnum, Enum, visited);
		}
		// ���س� w ���ⶥ�� v ����һ���ڽӵ�Ķ��� 
		w = NextNeighbor(G, v, w);
	} 
} 

bool istree(){
	int Vnum = 0, Enum = 0;
	
	bool visited[Max];
	
	for(int i = 0; i < Max; i++){
		visited[i] = false;
	}
	
	// ������ͼ����ǰ���㣬����������ߵĸ�����visited
	DFS(G, 1, Vnum, Enum, visited);
	if(Vnum == G.vexnum && Enum == 2*(G.vexnum - 1)){
		return true;
	}
	return false;
}
