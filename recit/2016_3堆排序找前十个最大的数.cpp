#include<stdio.h>
#include<stdlib.h>

/*
			�ѵ�������һ����ȫ�������У����ڵ�������������Ƕ� 
			�ѵ���֮ǰ������Ҫ ��֤�������������Ƕ� 
*/	 

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

// k��Ҫɸѡ���ı��
// end���������һ�����ı�� 
void sift(int r[], int k, int end){
	int i = k; // ���ڵ� 
	int j = 2 * k; // ���ӽڵ� 
	while(j <= end){ // j <= end����ֹ�����±�Խ�� 
		if(j < end && r[j] < r[j + 1]){
			// j < end��˵�� ��ǰ�ýڵ� ���Һ���
			// r[j] < r[j + 1]��������ֵ < ������ֵ 
			j++; // j ָ�� ��������ֵ�ϴ��ߣ������� 
		}
		// �����ֵ < ���ӽ��ֵ 
		if(r[i] < r[j]){
			swap(r[i], r[j]);
		}
		// ���½��е��� 
		i = j;
		j = 2 * i;
	}
}

void Find(int a[], int n, int b[], int m){
	int k;
	// ���� ����ѣ��������Ͻ��е��� 
	for(k = n / 2; k >= 1; k--){
		sift(a, k, n);
	}
	
	// ���� �����µ����� 
	for(k = 1; k <= m; k++){
		// �� ÿ��Ѱ�ҵ������ֵ �洢�� b[i] �� 
		b[k] = a[1];  
		// �� ��ǰ�ĶѶ� �� ��ǰ�����������һ�� ���н���
		swap(a[1], a[n - k + 1]);
		// 1����Ҫ�����ĸ����
		// n - k����Ҫ������Ԫ�ظ��� 
		sift(a, 1, n - k);
	}
} 

int main(){
	// a[0] δʹ�� 
	int a[8001];
	
	for(int i = 1; i <= 8000; i++){
		a[i] = 8001 - i;
	}
	
	int b[11]; 

	Find(a, 8000, b, 10);
	
	printf("����ǰ 10 ����Ϊ��");
	for(int i = 1; i <= 10; i++){
		printf("%d	", b[i]);
	}
	
	return 0;
}
