#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

int n = 9;

int a[10] = {1, 2, 3, 4, 6, 7, 8, 9, 10};

void find(int a[], int x){
	int left = 0, right = n - 1;
	int mid;
	while(left <= right){
		mid = (left + right) / 2;
		printf("mid = %d, a[%d] = %d\n", mid, mid, a[mid]);
		if(x == a[mid]){
			break;
		}
		else if(x < a[mid]){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	
	printf("left = %d, right = %d \n", left, right); 
	
	// �ҵ���Ԫ�ز������һ��Ԫ�أ��ſ��Ժͺ�һ�����н��� 
	if(a[mid] == x && mid != n - 1){
		int temp = a[mid];
		a[mid] = a[mid + 1];
		a[mid + 1] = temp; 
	}
	// û���ҵ� 
	if(left > right){
		// ִ�� ���Ʋ��� 
		int i;
		for(i = n - 1; i > right; i--){
			a[i + 1] = a[i];
		}
		// ����Ԫ�� ������  right�ĺ�һ��Ԫ�� 
		a[i + 1] = x;
		n = n + 1;
	}
}

void show(int a[]){
	for(int i = 0; i < n; i++){
		printf("%d	", a[i]);
	}
	printf("\n"); 
}

int main(){
	
	show(a);
	find(a, 7);
	show(a);
	return 0;
} 
