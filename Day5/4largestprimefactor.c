#include <stdio.h>

int prime(int n)
{
    int i, isprime = 0;
    if (n < 2)
    {
        return 0;
    }
    else
    {
        for (i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                isprime = 1;
                break;
            }
        }
    }

    if (isprime == 0)
    {
        return n;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, i, larg = 0;

    printf("enter a no:");
    scanf("%d", &n);

    if (n > 0)
    {
        for (i = 2; i <= n; i++)
        {
            if (n % i == 0 && i == prime(i))
            {
                larg = i;
            }
        }
        printf("largest prime factor of %d is %d", n, larg);
    }

    else
    {
        printf("u entered a wrong no");
    }
    return 0;
}
