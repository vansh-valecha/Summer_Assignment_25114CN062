// Write a program to Selection sort.

#include <stdio.h>
#include <stdlib.h>

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

void selsort(int a[], int n)
{
    int i, j, c;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
        }
    }
}
int main()
{
    int n, *a, i, j;
    printf("enter size of array:");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    printf("enter array:");
    input(a, n);
    selsort(a, n);
    printf("sorted array is \n");
    output(a, n);
    free(a);
    return 0;
}
