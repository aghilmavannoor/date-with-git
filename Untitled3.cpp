#include<stdio.h>
#include<stdlib.h>
int ptesting(int n,int k)
{
int i=1,remainder,r;
L:
r=(rand()%(n-2))+2;
remainder=n%r;
if(remainder==0)
   goto out;
else
   i++;
if(i<=k)
   goto L;
printf("No is Prime ");
return 0;
out:
printf("No is Composite");
    return 0;
}
 
int main()
{
int N,k;
printf("Enter a Number\n");
scanf("%d",&N);
printf("Enter minimum elements you want to check\n");
scanf("%d",&k);
ptesting(N,k);
return 1;
}

