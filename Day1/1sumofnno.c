#include<stdio.h>
int main()
{
    int n,s=0,i;
    printf("enter a no=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        s=s+i;
    }
    printf("sum of n natural number is %d",s);
}
