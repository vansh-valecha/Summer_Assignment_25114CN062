#include<stdio.h>
int main()
{
    int n,i,a,sum=0;
    printf("enter a no = ");
    scanf("%d",&n);
    while(n!=0)
    {
        a=n%10;
        sum=sum+a;
        n=n/10;
    }
    printf("sum of digit of number %d is %d",n,sum);
}
