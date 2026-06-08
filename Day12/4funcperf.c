//Write a program to Write function for perfect number
#include<stdio.h>
//sum of its division except itself is equal to that number is  perfect no 
int perf(int n)
{
    int i,sum=0;
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum=sum+i;
        }
    }
    return sum;
}

int main()
{
    int n;
    printf("enter a no:");
    scanf("%d",&n);
    if(n==perf(n))
    {
        printf("%d is a perfect no",n);
    }
    else{
        printf("%d is not a perfect no",n);
    }
    return 0;
}
