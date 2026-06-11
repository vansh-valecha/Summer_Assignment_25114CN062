//Write a program to Move zeroes to end.
#include <stdio.h>
#include <stdlib.h>

// this function take the input array
void input(int a[], int n)
{
    int i;
    printf("enter array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
// this function print the output array
void output(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
// i called function in a function for output
void zero(int a[], int n)
{
    int i, k = 0;
    // first all the non zero no get seprated
    for (i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            a[k] = a[i];
            k++;
        }
    }
    // after all non zero no this will add zero
    while (k < n)
    {
        a[k] = 0;
        k++;
    }
    printf("output array:");
    output(a, n);
}

int main()
{
    int n, *a;
    printf("enter size of array:");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    input(a, n);
    zero(a, n);
    free(a);
    return 0;
}
