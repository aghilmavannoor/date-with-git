

//Driver Code 

#include<stdio.h> 

#include<stdlib.h> 

#include "quick_H.h" 

#define NUM_NUMBERS 10000000 

  

void print_array(int arr[], int n) { 

    for (int i = n-50; i < n; i++) { 

        printf("%d ", arr[i]); 

    } 

    printf("\n"); 

} 

  

int main() { 

    int i; 

	int *arr=(int *)malloc(NUM_NUMBERS *sizeof(int)); 

	 

	const char *file_path="D:\\7th semester\\rand_nm.txt"; 

	FILE *file=fopen(file_path,"r"); 

	for(i=0;i<NUM_NUMBERS;i++) 

	{ 

		if(fscanf(file,"%d",&arr[i])!=1) 

		{ 

			printf("Error\n"); 

			fclose(file); 

		} 

		 

	} 

    print_array(arr,NUM_NUMBERS); 

  

    int choice; 

    printf("\nChoose a sorting algorithm:\n"); 

    printf("1. Quick Sort\n"); 

    printf("2. Randomized Quick Sort\n"); 

    printf("Enter your choice: "); 

    scanf("%d", &choice); 

  

    switch (choice) { 

        case 1: 

            void quicksort(int a[],int low,int high); 

            printf("Sorted array using Quick Sort: "); 

            break; 

        case 2: 

            void rquicksort(int a[], int low, int high); 

            printf("Sorted array using Random Quick Sort: "); 

            break; 

        default: 

            printf("Invalid choice.\n"); 

            return 1; 

    } 

  

    print_array(arr, NUM_NUMBERS); 

    return 0; 

}

