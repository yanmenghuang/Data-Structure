#include<stdio.h>
#include<stdlib.h>

using namespace std;

// �����±�� 1 ��ʼ 
int is_min(int a[], int len){
	// ż���������� ��֧��� 
	if(len % 2 == 0){
		// �ж� ��֧��� 
		if(a[len / 2] > a[len]){
			// ��֧��㲻���� ֱ�ӽ��� 
			return 0;
		}
		// �ж� ˫֧��� 
		for(int  i = len / 2 - 1; i >= 1; i--){
			if(a[i] > a[2*i] || a[i] > a[2*i + 1]){
				return 0;
			}
		}
	}
	// ������
	else{
		for(int i = len / 2; i >= 1; i--){
			if(a[i] > a[2*i] || a[i] > a[2*i + 1]){
				return 0;
			}
		}
	}
	
	return 1; 
}

int main(){
	
	int a[8] = {0, 1, 3, 2, 5, 4, 0};
	
	int i = is_min(a, 6);
	
	printf("%d	", i);
	
	return 0;
} 
