
#include <stdio.h>
#include <stdlib.h>

int bubblesort(int a[],int n);
int main()
{
    int a[50],i,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    printf("\ngenerating the random elements of array\n");
    for(i=0;i<n;i++)
    {
        a[i]= rand()%n;
    }
    printf("\nThe array is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    bubblesort(a,n);

    printf("\nThe sorted array is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int bubblesort(int a[],int n)
{
    int i,j,temp,flag;
    for(i=0;i<n-1;i++)
    {
        flag =0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag =1;
            }
        }
        if(flag == 0)
        {
            return 0;
        }
    }

    return 0;
}

