//Write a program to Binary search. 

#include <stdio.h>
#include <stdlib.h>
//for sorted array
void input(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void output(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
//divide array in half & then again & then again 
int search(int a[], int n,int ele)
{
    int beg=0,end=n-1,mid,f=-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(a[mid]==ele)
        {
            f=mid;
            break;
        }
        else if(ele<a[mid])
        {
           end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
     return f;
}

int main()
{
    int n,*a,ele,ch;
    printf("enter size of array:");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
     printf("enter sorted array:");
    input(a,n);
    printf("enter element to be search:");
    scanf("%d",&ele);
    ch=search(a,n,ele);
    if(ch==-1)
    {
        printf("element not found");
    }
    else{
        printf("%d is found at %d position",ele,ch+1);
    }
    free(a);
    return 0;
}
