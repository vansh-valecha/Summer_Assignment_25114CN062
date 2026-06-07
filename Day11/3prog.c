#include <stdio.h>

int prime(int n)
{
    int i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;

    printf("enter a no:");
    scanf("%d", &n);
    if (prime(n) == 0)
    {
        printf("%d is not a prime no", n);
    }
    else
    {
        printf("%d is a prime no", n);
    }
}
