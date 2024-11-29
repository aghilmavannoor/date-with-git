#include <stdio.h>
#define MAX 100
int b[MAX];  
void merge(int arr[], int low, int mid, int high) {
    int h = low;
    int i = low;
    int j = mid + 1;
    for (; h <= mid && j <= high; i++) {
        if (arr[h] <= arr[j]) {
            b[i] = arr[h];
            h++;
        } else {
            b[i] = arr[j];
            j++;
        }
    }
    for (; h <= mid; h++, i++) {
        b[i] = arr[h];
    }
    for (; j <= high; j++, i++) {
        b[i] = arr[j];
    } 
    for (i = low; i <= high; i++) {
        arr[i] = b[i];
    }
}
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high); 
        merge(arr, low, mid, high);
    }
}
void printArray(int arr[], int n) {
	int i;
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[MAX];
    int i,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    FILE* file = fopen("../random_variables.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    for ( i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    printf("Given array is \n");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}


