#include <stdio.h>

int fact(int n)
{
    int i, fact = 1;
    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int main()
{
    int z, n, a, sum = 0;

    printf("enter a no which is to be checked:");
    scanf("%d", &n);
    if (n != 0)
    {
        z = n;

        while (n != 0)
        {
            a = n % 10;
            sum = sum + fact(a);
            n = n / 10;
        }

        if (z == sum)
        {
            printf("%d is a strong number", z);
        }
        else
        {
            printf("%d is not a strong no", z);
        }
    }
    else
    {
        printf("u entered a wrong no");
    }

    return 0;
}
