#include <stdio.h>

int main()
{
    int n, i, isPrime = 0;

    printf("enter a no = ");
    scanf("%d", &n);

    if (n <= 1)
    {
        printf("%d is not a prime no", n);
        return 0;
    }

    for (i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime = 1;
            break;
        }
    }

    if (isPrime==0)
    {
        printf("%d is a prime no", n);
    }
    else
    {
        printf("%d is not a prime no", n);
    }

    return 0;
}
