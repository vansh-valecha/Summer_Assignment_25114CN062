#include <stdio.h>

int main()
{
    int n, i;

    printf("enter a no which has to be factories:");
    scanf("%d", &n);

    if (n > 0)
    {
        printf("factor of %d are--\n", n);
        for (i = 1; i <= n; i++)
        {
            if (n % i == 0)
                printf("%d\n", i);
        }
    }

    else
    {
        printf("u entered a wrong no");
    }
    return 0;
}
