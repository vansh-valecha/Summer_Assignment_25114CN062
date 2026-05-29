#include<stdio.h>
int main()
{
    int n,z,i,a,rev=0;
     printf("enter a no = ");
     scanf("%d",&n);
     z=n;
     while(n!=0)
        {
            a=n%10;
            rev=rev*10+a;
            n=n/10;
        }
     if(rev==z)
     {
          printf("no is palindrom");
     }
     else
     {
        printf("not a palindrom no");
     }

}
