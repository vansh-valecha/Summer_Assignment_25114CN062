#include <stdio.h>
int fact(int n)
{
    int i, fa = 1;
    for (i = 1; i <= n; i++)
    {
        fa = fa * i;
    }
    return fa;
}

int main()
{
    int n;
    printf("enter a no:");
    scanf("%d", &n);
    printf("fact of %d is %d", n, fact(n));
    return 0;
}
