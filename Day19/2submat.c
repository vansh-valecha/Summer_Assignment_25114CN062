// Write a program to Subtract matrices.

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
    int n1, n2, m1, m2, i, j, a[10][10], b[10][10], c[10][10];
    printf("enter row of 1st matrix:");
    scanf("%d", &n1);
    printf("enter column of 1st matrix:");
    scanf("%d", &m1);
    printf("enter row of 2nd matrix:");
    scanf("%d", &n2);
    printf("enter column of 2nd matrix:");
    scanf("%d", &m2);
    if (n1 == n2 && m1 == m2)
    {
        printf("enter 1st matrix:");
        input(a, n1, m1);
        printf("enter 2nd matrix:");
        input(b, n2, m2);
        printf("first matrix:\n");
        output(a, n1, m1);
        printf("second matrix:\n");
        output(b, n2, m2);
        printf("sum:\n");
        for (i = 0; i < n1; i++)
        {
            for (j = 0; j < m1; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        output(c, n1, m1);
    }
    else
    {
        printf("addition not possible");
    }
    return 0;
}
