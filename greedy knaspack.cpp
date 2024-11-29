#include <stdio.h> 
void fractionalKnapsack(int W[], int V[], int M, int n) { 
    float cost[n], total = 0.0; 
    int i, j; 
    for (i = 0; i < n; i++) { 
        cost[i] = (float)V[i] / W[i]; 
    } 
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++) { 
            if (cost[j] < cost[j + 1]) { 
                float temp = cost[j]; 
                cost[j] = cost[j + 1]; 
                cost[j + 1] = temp;
                int tempW = W[j];
                W[j] = W[j + 1]; 
                W[j + 1] = tempW; 
                int tempV = V[j]; 
                V[j] = V[j + 1]; 
                V[j + 1] = tempV; 
            } 
        } 
    } 
    i = 0; 
    while (i < n) { 
        if (W[i] <= M) {   
            M -= W[i]; 
            total += V[i]; 
        } else {   
            total += (float)V[i] * M / W[i]; 
            break; 
        } 
        i++; 
}
    printf("Maximum Profit: %.2f\n", total); 
} 
int main() { 
    int n, M;
    printf("Enter the number of items: "); 
    scanf("%d", &n); 
    printf("Enter the capacity of the knapsack: "); 
    scanf("%d", &M); 
    int W[n], V[n]; 
    printf("Enter the weights and values of each item:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Item %d (Weight, Value): ", i + 1); 
        scanf("%d %d", &W[i], &V[i]); 
    } 
    fractionalKnapsack(W, V, M, n);   
	return 0; 
}















