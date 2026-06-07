#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int a, b;
    printf("enter 1st no:");
    scanf("%d", &a);
    printf("enter 1st no:");
    scanf("%d", &b);
    printf("max between %d & %d is %d", a, b, max(a, b));
    return 0;
}
