#include <stdio.h>
#include <stdlib.h>

int ptesting(int n, int k) {
    int i = 1, remainder, r;

    if (n <= 1) { 
        printf("The number %d is neither prime nor composite.\n", n);
        return 0;
    }

L: 
    r = rand();
    remainder = n % r;

    if (remainder == 0)
        goto out;
    else
        i++;

    if (i <= k)
        goto L;

    printf("The number %d is Prime.\n", n);
    return 0;

out:
    printf("The number %d is Composite (divisible by %d).\n", n, r);
    return 0;
}

int main() {
    int N, k;

    printf("Enter a number to test for primality:\n");
    scanf("%d", &N);

    printf("Enter the number of iterations:\n");
    scanf("%d", &k);

    ptesting(N, k);

    return 0;
}

