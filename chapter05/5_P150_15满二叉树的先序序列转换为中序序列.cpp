#include<stdio.h>
#include<stdlib.h>

using namespace std;

void PreToIn(char pre[], int l1, int h1, char in[], int l2, int h2){
	int half; // �����������ٽ�ֵ
	
	if(l1 <= h1){ // �ݹ����������� <= ĩβ 
		// �� ��ǰ����� ���ڵ�ǰ��λ�� ���� �������λ�� 
		half = (h1 - l1) / 2; // ĩβ - ���� 
		printf("l1 = %d, h1 = %d, l2 = %d, h2 = %d, half = %d\n", l1, h1, l2, h2, half);
		// l2 + half����ǰ���ڵ� �����������е��±� 
		in[l2 + half] = pre[l1];
		printf("l2 + half = %d, in[l2 + half]= %c \n",l2 + half, in[l2 + half]);
		
		// �����з�Ϊ �������� 
		// �������ݹ� 
		PreToIn(pre, l1+1, l1+half, in, l2, l2+half-1);
		printf("\n");
		// �������ݹ�
		PreToIn(pre, l1+half+1, h1, in, l2+half+1, h2); 
	} 
}

int main(){
	// �������� ����ܸ���Ϊ ����            
	char pre[7]= {'A', 'B', 'D', 'E', 'C', 'F', 'G'}; 
	//       0    1    2    3    4    5    6
	// ����D    B    E    A    F    C    G 
	char in[7];
	
	PreToIn(pre, 0, 6, in, 0, 6);
	
	for(int i = 0; i < 7; i++){
		printf("%c	", in[i]);
	}
	return 0;
} 
