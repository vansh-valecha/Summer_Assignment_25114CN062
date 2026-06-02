#include <stdio.h>

int main()
{
    int n, z, a, sum = 0;
    printf("enter a decimal no:");
    scanf("%d", &n);
    z = n;
    while (n != 0)
    {
        a = n % 2;
        if (a == 1)
        {
            sum++;
        }
        n = n / 2;
    }

    printf("set bit in %d is %d", z, sum);
    return 0;
}
