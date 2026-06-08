//Write a program to Write function for palindrome.
#include<stdio.h>
// it extract last digit from number & add position wise as once tens & so on & in last return the count digit 
int pali(int n)
{
    int count=0;
    while(n!=0)
    {
        count=count*10+n%10;
        n=n/10;
    }
    return count;
}

int main()
    {
       int n;
       printf("enter a no:");
       scanf("%d",&n);
       // agr reverse no or original no same hua to wo palindrom no hoga
       if(pali(n)==n)
       {
        printf("%d is a palindrom no",n);
       }
       else{
        printf("%d is not a palindrom no",n);
       }
      return 0;
    }
