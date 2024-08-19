#include <stdio.h>

#define Max 20

// ��������������Ԫ�ص�ֵ
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �ָ����飬�����طָ���±�
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // ѡȡ���һ��Ԫ����Ϊ��׼
    int i = low - 1; // ��¼С�ڻ�׼��Ԫ�ص�λ��

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// ���������㷨
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // ����
        int partitionIndex = partition(arr, low, high);

        // �ݹ����򻮷ֵ�������
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// ��ӡ����
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a[Max];
	int n, k;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);

    printf("Original array: ");
    printArray(a, n);

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    printArray(a, n);
    printf("\n%d", a[k - 1]);

    return 0;
}

