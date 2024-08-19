#include<stdio.h>
#include<stdlib.h>

typedef struct lnode{
	int n;
	int a[6];
}SqList;

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(SqList &L){
	int low = 0, high = L.n - 1;
	bool flag = true;
	
	// flag�����ڼ�¼ÿһ�˱����Ƿ��н��� 
	// û�н�����˵�����Ѿ����򣬿�����ǰ���� 
	while(low <= high && flag){
		flag = false;
		for(int i = low; i < high; i++){
			if(L.a[i] > L.a[i+1]){
				swap(L.a[i], L.a[i+1]);
				flag = true;
			}
		} 
		high--;
		
		for(int j = high; j > low; j--){
			if(L.a[j] < L.a[j-1]){
				swap(L.a[j], L.a[j-1]);
				flag = true;
			}
		}
		low++;
	}
}

int main(){
	
	SqList L;
	L.n = 6;
	
	for(int i = 0; i < L.n; i++){
		printf("������� %d ������", i + 1);
		scanf("%d", &L.a[i]);
	}
	
	BubbleSort(L);
	
	for(int i = 0; i < L.n; i++){
		printf("%d	", L.a[i]);
	}
	
	return 0;
}
