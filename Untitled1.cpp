PROGRAM: 

//Header File 

#ifndef sortings_H 

#define sortings_H 

void merge(int a[],int low,int mid,int high); 

void mergesort(int A[],int low,int high); 

void interchange(int a[],int i,int j); 

int partition(int a[],int low,int high); 

void quicksort(int a[],int low,int high); 

void bubbleSort_noflag(int arr[], int n); 

void bubbleSort_flag(int arr[], int n); 

#endif 

 

//Implementation File 

#include<stdio.h> 

#include <stdlib.h> 

#include "sortings_H.h" 

#define NUM_NUMBERS 10000 

void merge(int a[],int low,int mid,int high) 

{ 

	int *b=(int *)malloc(NUM_NUMBERS *sizeof(int)); 

	if(b == NULL) 

	printf("Memory not allocated"); 

	int k=low,i=low,j=mid+1; 

	while(i <= mid && j <= high) 

	{ 

		if(a[i] <= a[j]) 

		{ 

			b[k++]=a[i++]; 

		} 

		else 

			b[k++]=a[j++]; 

		 

	} 

	while(i <= mid) 

	b[k++]=a[i++]; 

	while(j <= high) 

	b[k++]=a[j++]; 

  

	for(i = low;i <= high; i++) 

	 a[i]=b[i]; 

	free(b); 

} 

void mergesort(int A[],int low,int high) 

{ 

	if(low < high) 

	{ 

		int mid=(low + high) / 2; 

		mergesort(A,low,mid); 

		mergesort(A,mid + 1,high); 

		merge(A,low,mid,high); 

		 

	} 

} 

void interchange(int a[],int i,int j) 

{ 

	int p=a[i]; 

	a[i]=a[j]; 

	a[j]=p; 

} 

  

int partition(int a[],int low,int high) 

{  

	int pivot=a[low],i=low,j=high; 

	do 

	{ 

		do 

		{ 

			i++; 

		}while(a[i]<pivot && (i<=high)); 

		do 

		{ 

			j--; 

		}while(a[j]>pivot && (j>=low)); 

		if(i<j) 

		{ 

			interchange(a,i,j); 

		} 

	}while(i<j); 

	a[low]=a[j]; 

	a[j]=pivot; 

	return j; 

} 

  

void quicksort(int a[],int low,int high) 

{ 

	int j; 

	if(low<high) 

	{ 

		j=partition(a,low,high+1); 

		quicksort(a,low,j-1); 

		quicksort(a,j+1,high); 

	} 

} 

void bubbleSort_noflag(int arr[], int n) {  

  

	int i,j;  

  

    for (i = 0; i < NUM_NUMBERS-1; i++) {  

  

        for (j = 0; j < NUM_NUMBERS- i-1 ; j++) {  

  

            if (arr[j] > arr[j + 1])  

  

                interchange(arr, j, j + 1);  

  

        }  

  

    }  

  

}  

void bubbleSort_flag(int arr[], int n) {  

  

	int i,j,flag;  

  

    for (i = 0; i < NUM_NUMBERS-1; i++) {  

  

    	flag=0;  

  

        for (j = 0; j < NUM_NUMBERS- i-1 ; j++) {  

  

            if (arr[j] > arr[j + 1])  

  

                {  

                	interchange(arr, j, j + 1);  

                    flag=1;  

                }  

        }  

        if (flag == 0)  

  

            break;  

		}  

} 

 

//Driver Code 

#include <stdio.h> 

#include <stdlib.h> 

#include "sortings_H.h" 

#define NUM_NUMBERS 1000000 

void print_array(int arr[], int n) { 

	int i; 

    for (i = n-50; i < n; i++) { 

        printf("%d ", arr[i]); 

    } 

    printf("\n"); 

} 

  

int main()  

{ 

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

	for(i=NUM_NUMBERS-50;i<NUM_NUMBERS;i++) 

	{ 

		printf("%d  ",arr[i]); 

	} 

  

    int choice; 

    printf("\nChoose a sorting algorithm:\n"); 

    printf("1. Bubble Sort with flag\n"); 

    printf("2. Bubble Sort without flag\n"); 

    printf("3. Merge Sort\n"); 

    printf("4. Quick Sort\n"); 

    printf("Enter your choice: "); 

    scanf("%d", &choice); 

  

    switch (choice) { 

        case 1: 

            bubbleSort_flag(arr,NUM_NUMBERS); 

            printf("Sorted array using Bubble Sort with flag: "); 

            break; 

        case 2: 

            bubbleSort_noflag(arr,NUM_NUMBERS);  

            printf("Sorted array using Bubble Sort without flag: "); 

            break; 

        case 3: 

            mergesort(arr,0,NUM_NUMBERS-1); 

            printf("Sorted array using Merge Sort: "); 

            break; 

        case 4: 

            quicksort(arr,0,NUM_NUMBERS-1); 

            printf("Sorted array using Quick Sort: "); 

            break; 

        default: 

            printf("Invalid choice.\n"); 

            return 1; 

    } 

  

    print_array(arr,NUM_NUMBERS); 

    return 0; 

}
