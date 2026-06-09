// Write a program to Count even and odd elements
#include <stdio.h>

int main()
{
    int n, i, a[100], ev = 0, od = 0;
    printf("enter size of array:");
    scanf("%d", &n);
    if (n < 100)
    {
        printf("enter array-");
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (i = 1; i <= n; i++)
        {
            if (a[i] % 2 == 0)
            {
                ev++;
            }
            else
            {
                od++;
            }
        }
        printf("even element in array is %d\n", ev);
        printf("odd element in array is %d", od);
    }
    else
    {
        printf("unsufficiant size");
    }
    return 0;
}
