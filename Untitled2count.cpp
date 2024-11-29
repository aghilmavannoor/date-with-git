#include <stdio.h>
#define MAX 1000 

void countingSort(int arr[], int n) {
    int count[MAX + 1] = {0}, output[n];

    for (int i = 0; i < n; i++) count[arr[i]]++;        // Count occurrences
    for (int i = 1; i <= MAX; i++) count[i] += count[i - 1]; // Cumulative count
    for (int i = n - 1; i >= 0; i--)                    // Build output array
        output[--count[arr[i]]] = arr[i];
    for (int i = 0; i < n; i++) arr[i] = output[i];     // Copy to original array
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements (0-%d): ", MAX);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

