#include <stdio.h>

int main()
{
    int n, z, a;
    long long bin = 0, p = 1;
    printf("enter a decimal no:");
    scanf("%d", &n);
    z = n;
    if (n != 0)
    {
        while (n != 0)
        {
            a = n % 2;
            bin = bin + a * p;
            p = p * 10;
            n = n / 2;
        }
        printf("%d in binary is %lld", z, bin);
    }
    else
    {
        printf("binary no:0");
    }
    return 0;
}
