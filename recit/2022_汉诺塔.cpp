#include<stdlib.h>
#include<stdio.h>

using namespace std;

/*
			ʱ�临�Ӷȣ�2�� n �η� - 1 
*/
// count��ȫ�ֱ������԰ᶯ�������� 
int count = 0;

void move(char c1, int n, char c2){
	printf("�� %d �Σ��� %d �����Ӵ� %c �ƶ��� %c\n", ++count, n, c1, c2);
} 

// ����Ŀ�ģ�n �����ӣ��� x ͨ�� y �ƶ��� z 
void Hanoi(int n, char x, char y, char z){
	if(n == 1){
		move(x, 1, z);
	}
	else{
		// n-1 �����ӣ��� x ͨ�� z ��ʱ �ƶ��� y 
		Hanoi(n-1, x, z, y);
		// �� �� n ������ �� x �ƶ�������Ŀ�� z 
		move(x, n, z);
		// n-1 �����ӣ��� y ͨ�� x �ƶ��� z
		Hanoi(n-1, y, x, z);
	}
}

int main(){
	
	int n;
	printf("Please input n:");
	scanf("%d", &n);
	
	Hanoi(n, 'X', 'Y', 'Z');
	
	return 0;
} 
