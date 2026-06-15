// Write a program to Find diagonal sum.
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
    int n, m, i, j, a[10][10], sm = 0;
    printf("enter row of 1st array:");
    scanf("%d", &n);
    printf("enter column of 1st array:");
    scanf("%d", &m);
    if (n == m)
    {
        printf("enter matrix:");
        input(a, n, m);
        printf("matrix is-\n");
        output(a, n, m);
//index same ho ga  to sum ho jaya ga jsa [0,0] [1,1] or phelesquare matrix hone chahiye
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (i == j)
                {
                    sm = sm + a[i][j];
                }
            }
        }
        printf("sum of diagonal element:%d", sm);
    }
    else
    {
        printf("sum is not possible");
    }
    return 0;
}
