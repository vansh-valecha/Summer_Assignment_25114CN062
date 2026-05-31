#include <stdio.h>

int main()
{
    int n, f1 = 0, f2 = 1, f3, i;
    printf("enter the no upto which u have to print:");
    scanf("%d", &n);

    if (n >= 1)
    {
        if (n == 1)
        {
            printf(" %d ", f1);
        }
        else
        {
            printf(" %d %d", f1, f2);
            for (i = 3; i <= n; i++)
            {
                f3 = f1 + f2;
                printf(" %d ", f3);
                f1 = f2;
                f2 = f3;
            }
        }
    }
    else
    {
        printf("not possible");
    }
    return 0;
}
