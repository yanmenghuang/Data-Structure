#include<stdio.h>
#include<stdlib.h>

using namespace std;

// n��Ԫ�ظ���    ����ռ䣺n + 1 �� 
// ���� ���η� ��˼�� 
void shellSort(int a[], int n){
	int d;
	for(d = n / 2; d >= 1; d = d / 2){
		// �� d Ϊ��������������ֱ�Ӳ������� 
		for(int i = d + 1; i <= n; i++){
			a[0] = a[i]; // a[0] �ݴ� a[i] ��ֵ 
			int j = i - d;  // j ָ�� ���������е����һ����¼ 
			// j > 0����ֹ�±�Խ�� 
			while(j > 0 && a[0] < a[j]){
				a[j + d] = a[j]; // ��¼���� d ��λ�� 
				j = j - d; // �Ƚ� ͬһ�����е�ǰһ����¼ 
			}
			a[j + d] = a[0];
		}
	}
}

int main(){
	
	int a[9] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
	
	for(int i = 1; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	printf("\n");
	
	shellSort(a, 8);
	
	for(int i = 1; i < 9; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
} 
