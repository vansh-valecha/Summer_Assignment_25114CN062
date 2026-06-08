//Write a program to Write function for Armstrong
#include<stdio.h>
#include<math.h>
//this code is not able to check 153 because of stystem 
int count(int n)
{
    int count=0;
    while(n!=0)
    {
        count++;
        n=n/10;
    }
    return count;
}
// it extract last digit from number & do power of that digit & addto sum & last return sum
int arm(int n)
{
    int sum=0,a;
    a=count(n);
    while(n!=0)
    {
        sum=sum+pow(n%10,a);
        n=n/10;
    }
    return sum;
}

int main()
{
    int n;
    printf("enter a no:");
    scanf("%d",&n);
    if(n!=0)
    {
        if(n==arm(n))
        {
            printf("%d is a arm strong no",n);
        }
        else{
            printf("%d is not a arm strong no",n);
        }
    }
    else{
        printf("u entered a wrong no");
    }    
    return 0;
}
