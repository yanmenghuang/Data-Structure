#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

// �ǵݹ���������㷨 
void setPartition(int a[], int low, int high, int n){
	// ȡ�м�ֵ�±� 
	int k = (low + high) / 2; 
	bool flag = true; 
	
	while(flag){
		
		int i = low;
		int pivot = a[low];
		for(int j = low + 1; j <= high; j++){
			// �� �Ȼ�׼ֵС��ֵ �ŵ�ǰ�� 
			if(a[j] < pivot){
				swap(a[++i], a[j]);
			}
		}
		
		// �� ��׼ֵ ���뵽����λ�� 
		swap(a[low], a[i]);
		
		// ��׼ֵ�±� �պõ��� s1 ���Ҷ� ���� 
		if(i == k-1){
			flag = false; 
		}
		// ��׼ֵ�±� С�� �����Ҷ˽��п��� �����ҵ��м�ֵ
		else if(i < k-1){
			low = i + 1;
		} 
		// ��׼ֵ�±� ���� ������˽��п��� �����ҵ��м�ֵ
		else{
			high = i - 1;
		}
	}
	
	int s1 = 0, s2 = 0;
	for(int i = 0; i < k; i++){
		s1 += a[i];
		printf("%d	", a[i]);
	}
	printf("s1 = %d\n", s1);
	
	for(int i = k; i < n; i++){
		s2 += a[i];
		printf("%d	", a[i]);
	}
	printf("s2 = %d\n", s2);
	
	printf("%d	", s2 - s1);
}

int main(){
	
	int a[9] = {0, -1, -2, 0, -10, 3, -4, 1};
	
	setPartition(a, 0, 8, 8);
	return 0;
} 
