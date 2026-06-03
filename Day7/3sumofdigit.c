#include <stdio.h>

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return n % 10 + sum(n / 10);
}

int main()
{
    int n;
    printf("enter a no:");
    scanf("%d", &n);
    if (n != 0)
    {
        printf("sum of digit of %d is %d", n, sum(n));
    }
    else
    {
        printf("0");
    }
    return 0;
}
