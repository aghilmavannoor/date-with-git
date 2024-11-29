#include<stdio.h>
#include<stdlib.h>
int w[6],x[6]={0},m,r=0,n=6;
void print(int x[],int n)
{
int i;
printf("[");
for(i=0;i<n;i++)
    printf("%d ",x[i]);
    printf("]\n");
    printf("Subsets are [");
     for(int i=0;i<6;i++)
    {
     if(x[i]==1)
     {
        printf("%d ",w[i]);
     }
    }
    printf("]\n");
    
}
void sumofsubset(int s,int k,int r)
{
int i;
if(k>=n)
return ;
    x[k]=1;
if(s+w[k]==m)
{
print(x,n);
}
    
else if( k+1<n &&  s+w[k]+w[k+1]<=m)
sumofsubset(s+w[k],k+1,r-w[k]);
x[k]=0;
if(s+r-w[k]>=m && k+1 < n &&  s+w[k+1]<=m)
{
sumofsubset(s,k+1,r-w[k]);
}
}
int main()
{
printf("Enter weights of elements: ");
    for(int i=0;i<6;i++)
    {
        scanf("%d",&w[i]);
        
    }
    printf("Enter the sum  ");
    scanf("%d",&m);
    //print(w,n);
    sumofsubset(0,0,r);
}

