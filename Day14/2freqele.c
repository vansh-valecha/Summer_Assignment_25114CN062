//Write a program to Frequency of an element. 
#include<stdio.h>

int main()
{
    int a[100],i,el,n,freq=0;
    printf("enter the size of array:");
    scanf("%d",&n);
    if(n>0&&n<=100)
    {
        printf("enter array:\n");
        //it will take tha array with the help of loop
        for(i=1;i<=n;i++)
        { 
            scanf("%d",&a[i]);
        }
        printf("enter the element whoes freq is to be checked:");
        scanf("%d",&el);
        for(i=1;i<=n;i++)
        {
            if(el==a[i])
            {
                freq++;
            }
        }
        //it will printf the possition of element in the array
        if(freq!=0)
        {
        printf("frequency of %d in array is %d",el,freq);
        }
        else{
            printf("element not found ");
        }
    }
    else{
        printf("size is insufficiant");
    }
    return 0;
}
