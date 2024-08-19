#include<stdio.h>
#include<stdlib.h>

using namespace std;

void PreToPost(char pre[], int l1, int h1, char post[], int l2, int h2){
	int half; // �����������ٽ�ֵ
	
	if(l1 <= h1){ // �ݹ����������� <= ĩβ 
		// �� ��ǰ����� ���ڵ�ǰ��λ�� ���� �������λ�� 
		post[h2] = pre[l1];
		// �����з�Ϊ �������� 
		half = (h1 - l1) / 2; // ĩβ - ���� 
		// �������ݹ� 
		PreToPost(pre, l1+1, l1+half, post, l2, l2+half-1);
		// �������ݹ�
		PreToPost(pre, l1+half+1, h1, post, l2+half, h2-1); 
	} 
}

int main(){
	// �������� ����ܸ���Ϊ ���� 
	char pre[7]= {'A', 'B', 'D', 'E', 'C', 'F', 'G'}; 
	char post[7];
	
	PreToPost(pre, 0, 6, post, 0, 6);
	
	for(int i = 0; i < 7; i++){
		printf("%c	", post[i]);
	}
	return 0;
} 
