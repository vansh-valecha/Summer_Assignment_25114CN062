// Write a program to Merge arrays.
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
    int *a, *b, *c, n, m, i;
    printf("enter size of 1st array:");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    printf("enter 1st array:");
    input(a, n);
    printf("enter size of 2nd array:");
    scanf("%d", &m);
    b = (int *)malloc(sizeof(int) * m);
    printf("enter 2nd array:");
    input(b, m);
    c = (int *)malloc(sizeof(int) * (m + n));
    // isme phele 3 array me phele 1 array aya ga phir 2 loop se 2 array ke element aya ga
    for (i = 0; i < n; i++)
    {
        c[i] = a[i];
    }
    for (i = 0; i < m; i++)
    {
        c[n + i] = b[i];
    }
    printf("merged array:");
    output(c, n + m);
    free(a);
    free(b);
    free(c);
    return 0;
}
