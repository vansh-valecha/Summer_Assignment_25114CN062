// Write a program to Find column-wise sum.

#include <stdio.h>
void input(int ar[10][10], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }
}
void output(int ar[10][10], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n, m, i, j, a[10][10], sm;
    printf("enter row of matrix:");
    scanf("%d", &n);
    printf("enter column of matrix:");
    scanf("%d", &m);
    if (n > 0 && n <= 10 && m > 0 && m <= 10)
    {
        printf("enter matrix:");
        input(a, n, m);
        printf("matrix:\n");
        output(a, n, m);
        for (i = 0; i < m; i++)
        {
            sm = 0;
            for (j = 0; j < n; j++)
            {
                sm += a[j][i];
            }
            printf("sum of %d column:%d\n", i + 1, sm);
        }
    }
    else
    {
        printf("wrong dimension of matrix");
    }
    return 0;
}
