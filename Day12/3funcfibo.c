//Write a program to Write function for Fibonacci. 
#include<stdio.h>

void fibo(int n)
{
    int i,f1=0,f2=1,f3;
    if(n==1)
    {
        printf("%d",f1);
    }
    else{
        printf("%d %d ",f1,f2);
        for(i=3;i<=n;i++)
        {
            f3=f1+f2;
            printf("%d ",f3);
            f1=f2;
            f2=f3;
        }
    }
}

int main()
{
    int n;
    printf("enter a no:");
    scanf("%d",&n);
    printf("fibonacci series upto %d is--\n",n);
    fibo(n);
  return 0;
}
