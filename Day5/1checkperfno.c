#include <stdio.h>

int main()
{
    int n, i, sum = 0;

    printf("enter a no to be checked:");
    scanf("%d", &n);

    if (n > 0)
    {
        for (i = 1; i < n; i++)
        {
            if (n % i == 0)
                sum = sum + i;
        }
        printf("%d\n", sum);
        if (sum == n)
        {
            printf("%d is a perfect no", n);
        }
        else
        {
            printf("%d is not a perfect no", n);
        }
    }

    else
    {
        printf("u entered a wrong no");
    }
    return 0;
}
