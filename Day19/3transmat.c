// Write a program to Transpose matrix.

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
    int n, m, i, j, a[10][10], tr[10][10];
    printf("enter row of matrix:");
    scanf("%d", &n);
    printf("enter column of matrix:");
    scanf("%d", &m);
    if (n == m)
    {
        printf("enter matrix:");
        input(a, n, m);
        printf("original matrix:\n");
        output(a, n, m);
        printf("transposed matrix:\n");
        // transpose ka liya hum ek alag array me [0][1] ki jga [1][0] kra ga
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                tr[j][i] = a[i][j];
            }
        }
        output(tr, m, n);
    }
    else
    {
        printf("transpose not possible");
    }
    return 0;
}
