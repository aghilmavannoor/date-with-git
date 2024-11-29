#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, M, k, i;
    int profit = 0, weight = 0;

    printf("Enter the number of elements \n");
    scanf("%d", &n);
    int w[n], p[n], x[n];

    printf("Enter the weights of elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter the profits of elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter capacity of knapsack\n");
    scanf("%d", &M);

    printf("Enter minimum profit value\n");
    scanf("%d", &k);
    for (i = 0; i < n; i++)
        x[i] = rand() % 2;

    printf("Solution vector is \n[");
    for (i = 0; i < n; i++)
        printf("%d  ", x[i]);
    printf("]\n");
    for (i = 0; i < n; i++) {
        profit += x[i] * p[i];
        weight += x[i] * w[i];
    }
    if (weight > M || profit < k)
        printf("Not feasible solution\n");
    else
        printf("Feasible solution\n");

    return 0;
}

