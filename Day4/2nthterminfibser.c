#include<stdio.h>

int main()
{
    int n ,f1=0 ,f2=1 ,f3,i ;
    printf("enter the term to find:");
    scanf("%d", &n);

    if(n>=1)
    {
        if(n==1)
        {
            printf("fibonaccie term at %d is %d ",n, f1 );
        }
        else if(n==2)
        {
            printf("fibonaccie term at %d is %d ",n, f2 );
        }
        else
        {
            for(i=3;i<=n;i++)
            {
                 f3=f1+f2;
                  f1=f2;
                  f2=f3;
            }
            printf("fibonaccie term at %d is %d ",n, f3 );
        }
    }
    else{
        printf("not possible");
    }
    return 0;
    
}