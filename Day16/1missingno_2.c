#include <stdio.h>
#include <stdlib.h>
//this will work for both sorted & unsorted arrays
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
//it will calculate the sum of n natural no & sub sum of array from it
int mis(int a[],int n)
{
    int total,sum=0,i;
    total=(n+1)*(n+2)/2;
    for(i=0;i<n;i++)
    {
       sum=sum+a[i];
    }
    return total-sum;
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
