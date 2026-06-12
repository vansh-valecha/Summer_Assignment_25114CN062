#include <stdio.h>
#include <stdlib.h>
//this is for sorted array only
// it will take the input array from user
void input(int a[], int n)
{
    int i;
    printf("enter array element from 1 to %d:",n+1);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
//it will compare index with array element
int mis(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       if(a[i]!=i+1)
       {
           return i+1;
       }
    }
    return n+1;
}
int main()
{
    int n, *a,m;
    printf("enter size of array:");
    scanf("%d", &n);
    // locate the memory for array of size n
    a = (int *)malloc(sizeof(int) * n);
    input(a, n);
    m=mis(a, n);
    printf("missing element in array is %d",m);
    free(a);
    return 0;
}
