#include<stdio.h>
int main()
{
    int n,i,a,rev=0;
    printf("enter a no = ");
    scanf("%d",&n);
    int z=n;
    while(n!=0)
    {
        a=n%10;
        rev=rev*10+a;
        n=n/10;
    }
    printf("reverse of the number %d is %d",z,rev);
}
