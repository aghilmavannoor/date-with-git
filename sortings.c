
//Implementation File 

#include<stdio.h> 

#include<stdlib.h> 

#include "quick_H.h" 

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

  

int randompartition(int a[], int low, int high) 

{ 

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

void rquicksort(int a[], int low, int high) 

{ 

	if (low < high) 

	{ 

		int j = randompartition(a, low, high + 1); 

		rquicksort(a, low, j - 1); 

		rquicksort(a, j + 1, high); 

	} 

} 

 

