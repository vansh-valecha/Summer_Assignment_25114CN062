// func to find sum of 2 no
#include <stdio.h>
int sum(int a, int b)
{
    return a + b;
}
int main()
{
    int a, b;
    printf("enter 1 no:");
    scanf("%d", &a);
    printf("enter 2 no:");
    scanf("%d", &b);
    printf("sum of %d & %d is %d", a, b, sum(a, b));
}
