#include<stdio.h>

int main()
{
    int a, b, i;

    printf("enter first no =");
    scanf("%d", &a);
    printf("enter second no =");
    scanf("%d", &b);

    for(i = 2;i <= a && i <= b; i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            printf(" %d ", i);
        }
    }
}
