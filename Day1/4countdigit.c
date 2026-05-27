#include<stdio.h>
int main()
{
    int n,i,a,count=0;
    printf("enter a no = ");
    scanf("%d",&n);
    while(n!=0)
    {
        a=n%10;
        count++;
        n=n/10;
    }
    printf("no of digit in %d is %d",n,count);
}