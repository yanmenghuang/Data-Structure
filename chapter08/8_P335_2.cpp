#include<stdio.h>
#include <stdlib.h>

using namespace std;

void bubblesort(int a[], int n){
	
	int low = 0, high = n-1;
	bool flag = true;
	// ѭ����������� < �Ҷ� ���� һ���н��� 
	while(low < high && flag){
		// ����ǰ Ĭ��һ��û�н��� 
		flag = false;
		// ��ǰ ��� �ţ�ð���ֵ 
		for(int i = low; i < high; i++){
			if(a[i] > a[i+1]){
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				// �н��� flag ��Ϊ true 
				flag = true;
			}
		} 
		// �Ҷ� ���� 
		high--; 
		// �Ӻ� ��ǰ �ţ�ð��С�� 
		for(int j = high; j > low; j--){
			if(a[j] < a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				flag = true;
			}
		} 
		low++;
	}
	
}

int main(){
	
	int a[10] = {7, 5, 9, 2, 6, 4, 3, 8, 1, 10};
	
	bubblesort(a, 10);
	
	for(int i = 0; i < 10; i++){
		printf("%d	", a[i]);
	}
	
	return 0;
}
