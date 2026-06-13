//Write a program to Find common elements. 
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
    int *a, *b, *c, n, m, i, j, l, k = 0, already;

    printf("Enter size of 1st array: ");
    scanf("%d", &n);

    a = (int *)malloc(sizeof(int) * n);

    printf("Enter 1st array: ");
    input(a, n);

    printf("Enter size of 2nd array: ");
    scanf("%d", &m);

    b = (int *)malloc(sizeof(int) * m);

    printf("Enter 2nd array: ");
    input(b, m);

    c = (int *)malloc(sizeof(int) * (m + n));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                already = 0;

                for (l = 0; l < k; l++)
                {
                    if (c[l] == a[i])
                    {
                        already = 1;
                        break;
                    }
                }

                if (already == 0)
                {
                    c[k] = a[i];
                    k++;
                }

                break;
            }
        }
    }

    if (k == 0)
    {
        printf("No common element found");
    }
    else
    {
        printf("common elements: ");
        output(c, k);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}
