#include<stdio.h>
#include<math.h>
// this code is not able to check the 153 beacuse of stored value of 5 cube is 124

int main()
{
    int n,i,a,z,b=0,arm=0;
    printf("enter a no to be checked:");
    scanf("%d",&n);
    if(n!=0)
    {
            z=n;
            while(n!=0)
            {
                a=n%10;
                b++;
                n=n/10;
            }
            n=z;
        while(n!=0)
            {
                a=n%10;
                arm=arm+pow(a,b);
                n=n/10;
            }
            if(arm==z)
            printf("arm strong");
            else
            printf("not a arm strong");
    }   
    else{
        printf("u entered a wrong no");
    }
    return 0;
}