// Write a program to Union of arrays.

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
    int *a, *b, *c, n, m, i, j, k = 0, found;
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

    // isme phele 3 array me phele array ka element aya ga or phir 2 array ka elemnt ana
    //se phele check ho ga ki same 3 me ha ya nhi .
    for (i = 0; i < n; i++)
    {
        c[k] = a[i];
        k++;
    }

    for (i = 0; i < m; i++)
    {
        found = 0;

        for (j = 0; j < k; j++)
        {
            if (b[i] == c[j])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            c[k] = b[i];
            k++;
        }
    }

    output(c, k);
    free(a);
    free(b);
    free(c);
    return 0;
}
