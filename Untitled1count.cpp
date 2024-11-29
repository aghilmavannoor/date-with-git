#include <stdio.h> 

  

  

int findMax(int A[], int n) { 

    int max = A[0]; 

    for (int i = 1; i < n; i++) { 

        if (A[i] > max) { 

            max = A[i]; 

        } 

    } 

    return max; 

} 

 void countingSort(int A[], int n, int k) { 

    int B[n];          

    int C[k + 1];       

    for (int i = 0; i <= k; i++) { 

        C[i] = 0; 

    } 

	for (int j = 0; j < n; j++) { 

        C[A[j]]++; 

    } 

    for (int i = 1; i <= k; i++) { 

        C[i] += C[i - 1]; 

    } 

    for (int j = n - 1; j >= 0; j--) { 

        B[C[A[j]] - 1] = A[j]; 

        C[A[j]]--; 

    } 

    for (int i = 0; i < n; i++) { 

        A[i] = B[i]; 

    } 

} 

  

int main() { 

    int n; 

    printf("Enter the number of elements: "); 

    scanf("%d", &n); 

    int A[n]; 

    printf("Enter the elements of the array: "); 

    for (int i = 0; i < n; i++) { 

        scanf("%d", &A[i]); 

    } 

    int k = findMax(A, n); 

    countingSort(A, n, k); 

	printf("Sorted array: "); 

    for (int i = 0; i < n; i++) { 

        printf("%d ", A[i]); 

    } 

    return 0; 

}
