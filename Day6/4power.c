#include <stdio.h>

int main()
{
    int x, n, i, pow = 1;

    printf("enter a base:");
    scanf("%d", &x);
    printf("enter power:");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        pow = pow * x;
    }

    printf("%d raise to the power %d is %d", x, n, pow);

    return 0;
}
