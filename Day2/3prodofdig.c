#include<stdio.h>
int main()
{
    int n,i,a,z,prod=1;
    printf("enter a no = ");
    scanf("%d",&n);
    z=n;
    while(n!=0)
    {
        a=n%10;
        prod=prod*a;
        n=n/10;
    }
    printf("product of digit of number %d is %d",z,prod);
}
