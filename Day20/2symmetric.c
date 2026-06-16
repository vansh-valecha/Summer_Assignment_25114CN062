// Write a program to Check symmetric matrix.

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
    int n, m, i, j, a[10][10], check = 0;
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

        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < m; j++) // isse sirf diagnal ka upper ka compare ho ga jisse efficiency jada ho gi
            {
                if (a[j][i] != a[i][j])
                {
                    check = 1;
                    break;
                }
            }
        }
        if (check == 0)
        {
            printf("above matrix is symmetric");
        }
        else
        {
            printf("not symmetric");
        }
    }
    else
    {
        printf("Symmetric check requires a square matrix");
    }
    return 0;
}
