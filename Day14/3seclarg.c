//Write a program to Second largest element. 
#include<stdio.h>

int main()
{
    int a[100],n,i,larg,sec=0;
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
        //it will find largest no between 1 & 2 index element then give that value in larg & sec
        if(a[1]>a[2])
        {
            larg=a[1];
            sec=a[2];
        }
        else
        {
            larg=a[2];
            sec=a[1];
        }
        //compare with other no 
        for(i=3;i<=n;i++)
        {
            if(a[i]>larg)
            {
                sec=larg;
                larg=a[i];
            }
            //if first case fail or agr koi no asa a jaya jo ki larg se chota ho sec se bada ho to
            else if(a[i]>sec && a[i]!=larg)
            {
                sec=a[i];
            }
        } 
        //print the output
        printf("second largest element in array is %d",sec);
    }
    else{
        printf("size is insufficiant");
    }
    return 0;
}
