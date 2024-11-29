#include<stdio.h> 
#include <stdlib.h> 
#include <time.h>  
#define NUM_NUMBERS 5000 
void interchange(int a[], int i, int j) 
{ 
	int temp = a[i]; 
	a[i] = a[j]; 
	a[j] = temp; 
}
int partition(int a[], int low, int high) {
	int random_index = low + rand() % (high - low);  
	interchange(a, low, random_index);  
	int pivot = a[low], i = low, j = high;
	do 
	{ 
		do 
		{ 
			i++; 
		} while (a[i] < pivot && i <= high); 
		do 
		{ 
			j--;
		} while (a[j] > pivot && j >= low);
		if (i < j) 
		{ 
			interchange(a, i, j); 
		} 
	} while (i < j); 
	interchange(a, low, j);  
	return j; 
} 

void quicksort(int a[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int j = partition(a, low, high + 1); 
		quicksort(a, low, j - 1);  
		quicksort(a, j + 1, high);  
	} 
} 
int main() 
{ 
	int i; 
	int *arr = (int *)malloc(NUM_NUMBERS * sizeof(int)); 
	srand(time(0)); 
	for (i = 0; i < NUM_NUMBERS; i++) 
	{ 
		arr[i] = i + 1; 
	} 
	printf("Last 60 numbers before sorting:\n");
	for (i = NUM_NUMBERS - 60; i < NUM_NUMBERS; i++) 
	{ 
		printf("%d  ", arr[i]); 
    } 
	printf("\n\n"); 
	quicksort(arr, 0, NUM_NUMBERS - 1); 
	printf("Last 60 numbers after sorting:\n"); 
	for (i = NUM_NUMBERS - 60; i < NUM_NUMBERS; i++) 
	{
		printf("%d  ", arr[i]); 
	} 
	printf("\n"); 
	free(arr); 
	return 0; 
}

