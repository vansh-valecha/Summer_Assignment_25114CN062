// Write a program to Intersection of arrays.
#include <stdio.h>
#include <stdlib.h>
// this code check only array which did not contain any duplicate no
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
    int *a, *b, *c, n, m, i, j, k = 0;
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
    // it will pick one element if array 1st check it with other one if found same then store it in c .
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                c[k] = a[i];
                k++;
            }
        }
    }
    if (k == 0)
    {
        printf("no common element found");
    }
    else
    {
        printf("Intersection of arrays:\n");
        output(c, k);
    }
    free(a);
    free(b);
    free(c);
    return 0;
}
