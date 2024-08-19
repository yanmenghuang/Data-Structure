#include<stdio.h>
#include<stdlib.h>

#define Max 50

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

// n ��Ҫ�����÷��ţ���Ϊδ�鵽Ԫ����Ҫ�ı����鳤�� 
int Find(int a[], int &n, int x){
	int low = 0, high = n - 1;
	int mid;
	while(low <= high){
		mid = (low + high) / 2;
		if(x == a[mid]){
			return mid; 
		}
		else if(x > a[mid]){
			// ���ұ��� 
			low = mid + 1;
		}
		else{
			// ������� 
			high = mid - 1;
		}
	}
	// δ�ҵ������в��� 
	for(int i = n - 1; i > high; i--){
		a[i + 1] = a[i];
	}
	// ����Ԫ�� ������ high �ĺ�һ��Ԫ�� 
	a[high + 1] = x;
	n = n + 1;
}

void disp(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d	", a[i]);
	}
	printf("\n"); 
}

int main(){
	
	int a[Max] = {1, 2, 3, 6, 7, 8, 9, 10, 15};
	int n = 9;
	disp(a, n);
	Find(a, n, 5);
	disp(a, n);
	
	return 0;
} 
