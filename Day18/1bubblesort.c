// Write a program to Bubble sort.

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

int main()
{
    int n, *a, i, j, temp;
    printf("enter size of array:");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    printf("enter array:");
    input(a, n);
    // it will change the position with the next no if condition satisfied basically check by all the no at once
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    output(a, n);
    free(a);
    return 0;
}
