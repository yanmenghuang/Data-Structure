#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define Max 50

struct SqList{
	// int a[Max] = {5, 5, 5, 5, 5, 5, 5, 5};
	int a[Max] = {3, 3, 5, 5, 5, 8, 8, 18};
	int length = 8;
};

// ������� ɾ���ظ�Ԫ�� 
void delete_duplicate(SqList &L){
	
	int i = 0;
	
	for(int j = 1; j < L.length; j++){
		if(L.a[i] != L.a[j]){
			L.a[++i] = L.a[j];
		}
	}
	
	L.length = i + 1;
	
}

// ������� ɾ���ظ�Ԫ�� 
void delete_dup(SqList &L){
	int count = 0;
	for(int i = 0; i < L.length; i++){
		bool flag = true;
		for(int j = i + 1; j < L.length; j++){
			// ��ǰԪ�� �� ������ 
			if(L.a[i] == L.a[j]){
				flag = false;
				break;
			}
		}
		// ��ǰԪ�� �� ����û�� 
		if(flag){
			bool f = true;
			for(int k = 0; k < count; k++){
				// ��ǰԪ�� �� ��ѡ����Ԫ���� �� 
				if(L.a[k] == L.a[i]){
					f = false;
				}
			}
			// ��ǰԪ�� ���� ��ѡ����Ԫ����
			if(f){
				L.a[count++] = L.a[i];
			}
		}
	}
	L.length = count;
}

void show(SqList s){
	if(s.length == 0){
		printf("���Ա�Ϊ��");
		return;
	}
	for(int i = 0; i < s.length; i++){
		printf("%d	", s.a[i]);
	}
	printf("\n"); 
}

int main(){
	
	SqList L;
	
	show(L);
	delete_duplicate(L);
	show(L);
	
	return 0;
}
