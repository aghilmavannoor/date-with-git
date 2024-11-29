#include <stdio.h>
#include <stdlib.h>
int linear_search(int a[],int size ,int search)
{
    int r =-2;
    for(int i = 0;i<size;i++)
        if(search == a[i])
        {
            r=i;
            break;
        }
    return r;
}
int main()
{
    int a[]={3,10,24,59,98};
    int search;
    int size=sizeof(a)/sizeof(a[0]);
    printf("Enter the value you to search :");
    scanf("%d",&search);
    int result = linear_search(a,size,search);
    if(result == -2)
        printf("Element is not present in array");
    else 
        printf("Element present in the index %d",result);
    return 0;
}


