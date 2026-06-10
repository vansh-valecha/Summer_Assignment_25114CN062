//Write a program to Linear search. 
#include<stdio.h>

int main()
{
    int a[100],n,i,el;
    printf("enter the size of array:");
    scanf("%d",&n);
    if(n<=100)
    {
        printf("enter array:\n");
        //it will take tha array with the help of loop
        for(i=1;i<=n;i++)
        { 
            scanf("%d",&a[i]);
        }
        printf("enter the element to  be searched:");
        scanf("%d",&el);
        for(i=1;i<=n;i++)
        {
            if(el==a[i])
            {
                break;
            }
        }
        //it will printf the possition of element in the array
        if(i!=n+1)
        {
        printf("%d is found at %d possition",el,i);
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
