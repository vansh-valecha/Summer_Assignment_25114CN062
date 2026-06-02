#include <stdio.h>

int main()
{
    int n, a, sum = 0,base=1 ;
    printf("enter a binary no:");
    scanf("%d", &n);

    while (n != 0)
    {
        a = n % 10;
        sum = sum + a * base;
        base=base*2;
        n = n / 10;
    }
    printf("decimal no is %d", sum);
}
