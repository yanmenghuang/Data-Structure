#include<stdio.h>
#include<stdlib.h>

using namespace std;

// &�������Ҫ���� 
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

// low �� 1 ��ʼ 
int min_k(int a[], int low, int high, int k){
	// �������� �����㷨 
	int i = low;
	// ��ȡ ��׼ֵ
	int p = a[low]; 
	// �ӵڶ�����ʼ���������� 
	for(int j = low + 1; j <= high; j++){
		if(a[j] < p){
			// i ���±� ���������ٽ��� 
			swap(a[++i], a[j]); 
		}
	} 
	// ����׼ֵ ���뵽 ����λ��
	swap(a[low], a[i]);
	
	
	// ��� ��׼λ�� = k����׼���� �� k С
	// �ݹ�������� 
	if(i == k){
		return a[i];
	} 
	// ��� ��׼λ�� > k���ڻ�׼��ߵݹ�ȥ�� �� k С
	else if(i > k){
		return min_k(a, low, i -1, k);
	}
	// ��� ��׼λ�� < k���ڻ�׼�ұߵݹ�ȥ�� �� k С
	else{
		return min_k(a, i + 1, high, k);
	}
}

// low �� 1 ��ʼ
// �ǵݹ�������� 
int min_k1(int a[], int low, int high, int k){
	
	int i;
	bool flag = true;
	// �ӵڶ�����ʼ���������� 
	while(flag){
		i = low;
		// ��ȡ ��׼ֵ
		int p = a[low]; 
		
		for(int j = low + 1; j <= high; j++){
			if(a[j] < p){
				// i ���±� ���������ٽ��� 
				swap(a[++i], a[j]); 
			}
		} 
		// ����׼ֵ ���뵽 ����λ��
		swap(a[low], a[i]);
		
		if(i == k){
			flag = false;
		}
		// ��� ��׼λ�� > k
		else if(i > k){
			high = i - 1;
		}
		// ��� ��׼λ�� < k
		else{
			low = i + 1;
		}
	}
	return a[i];
}

int main(){
	
	int a[10] = {0, 7, 5, 17, 2, 6, 4, 3, 8, 1};
	
	int k = min_k(a, 1, 9, 9);
	
	printf("%d", k); 
	
	return 0;
}
