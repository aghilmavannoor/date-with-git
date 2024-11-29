#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x < a[mid])
        {
            high = mid - 1;
        }
        else if (x > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}


int main(){
    int a[50], n, x;
    printf("Enter the number of array: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    int result = binarySearch(a, n, x);
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", result);
    }
    return 0;
}
