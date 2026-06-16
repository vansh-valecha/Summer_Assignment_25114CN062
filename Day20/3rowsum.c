// Write a program to Find row-wise sum.

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
    if (m != 0 && n != 0)
    {
        printf("enter matrix:");
        input(a, n, m);
        printf("matrix:\n");
        output(a, n, m);
        // row wise sum ke liya hum pehle ek row select kar ga or usme jitne column ho ga unka sum kar ga
        for (i = 0; i < n; i++)
        {
            sm = 0;
            for (j = 0; j < m; j++)
            {
                sm += a[i][j];
            }
            printf("sum of %d row:%d\n", i + 1, sm);
        }
    }
    else
    {
        printf("wrong dimension of matrix");
    }
    return 0;
}
