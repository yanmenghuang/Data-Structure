#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define Max 10

using namespace std;

/*
			S[0]��T[0]��0�ŵ�Ԫ�洢�ַ������� 
*/ 

// �ַ����±�� 1 ��ʼ
void Next(char T[], int next[]){
    // next���� ��һ�� Ĭ����Ϊ 0 
    next[1] = 0;
	// j������ǰ׺ 
    int j = 0;
    // i�������׺ 
    int i = 1;
    
    while(i < T[0]){
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            // next[i] ��ŵ��� i-1�� ���ǰ�� 
            next[i] = j;
            // next[++i] = ++j; // �������дΪһ�� 
        }
		else{
			// ��ǰ�ַ�����ȣ����ݵ��Ѿ��ҵ�����󳤶�ǰ���Ӵ� 
            j = next[j];
        }
    }
}

void NextVel(char T[],int nextvel[]){
	nextvel[1] = 0;
	
    int i = 1;
    int j = 0;
    while(i < T[0]){
        if(j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            if(T[i] != T[j]){
            	nextvel[i] = j;
			}
			else{
				nextvel[i] = nextvel[j];
			}
        }
		else{
            j = nextvel[j];
        }
    }
}

void printNext(int next[], int n){
	for(int i = 1; i <= n; i++){
		printf("%d	", next[i]);
	}
	printf("\n");
}

void printNextval(int nextval[], int n){
	for(int i = 1; i <= n; i++){
		printf("%d	", nextval[i]);
	}
	printf("\n");
}

int KMP(char S[], char T[], int pos){
	int i = pos;
	int j = 1;
	
	int next[Max];
	Next(T, next);
	// printNext(next, 8); 
	while(i <= S[0] && j <= T[0]){
		// j == 0��ģʽ�� ���ݵ��ʼ
		// S[i] == T[j]����ǰƥ����ַ���� 
		if(j == 0 || S[i] == T[j]){
			i++;
			j++;
		}
		// ��ǰƥ����ַ�����ȣ�j ���л��ݣ��ҵ�����Ѿ�ƥ����Ӵ�  
		else{
			j = next[j];
		}
	}
	if(j > T[0]){
		// ƥ��ɹ� 
		printf("ƥ��ɹ���ƥ���±�Ϊ��%d\n", i - T[0]);
		return i - T[0];
	}
	else{
		printf("ƥ��ʧ�ܣ�����"); 
		return 0;
	}
}

// ��ǰ�ַ� ǰ���Ӵ���󳤶� 
void MaxL(int T[], int maxl[]){}

int main(){
	char S[18] = {17, 'a', 'c', 'a', 'b', 'a', 'a', 'b', 'a', 'a', 'b', 'c', 'a', 'c', 'a', 'a', 'b', 'c'};
	char T[9] = {8, 'a', 'b', 'a', 'a', 'b', 'c', 'a', 'c'}; 
	
	KMP(S, T, 1);
	
	int next[Max];
	int nextval[Max];
	
	Next(T, next);
	NextVel(T, nextval);
	printNext(next, 8);
	printNextval(nextval, 8);
	/*
		j		1	2	3	4	5	6	7	8    
	 ģʽ��     a   b   a   a   b   c   a   c
	  maxl		0   0   1   1   2   0   1   0
	  next      0   1   1   2   2   3   1   2
	  nextval   0   1   0   2   1   3   0   2 
	  
	  next[1] = 0��(��ʼ���� 
	  next[i] = maxl[i-1] + 1	(i > 1)
	  next[i]���� i ʧЧʱ��T����next[i]��ʼ�Ƚ�
	  
	  �� maxl[i] != next[i]��nextval[i] = next[i]
	  �� maxl[i] == next[i]��nextval[i] = next[ next[i] ] 
	   
	*/
	
	
	return 0;
}
