#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void KDLS(int A[], int n, int X) {
    srand(time(0));
    int i = rand();
    i = i % n;  // Generate a random index within bounds of the array
    if (A[i] == X)
        printf("\nElement found at index %d\n", i);
    else
        printf("\nElement not found at index %d!\n", i);
}

int main() {
    int A[8] = {100, 101, 102, 103, 104, 105, 106, 107}, target;
    printf("Enter element to search: ");
    scanf("%d", &target);  // Corrected to pass the address of 'target'
    
    KDLS(A, 8, target);
    
    return 0;  // This is the correct place for return 0
}

