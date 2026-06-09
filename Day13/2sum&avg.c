//Write a program to Find sum and average of array. 
#include <stdio.h>

int main()
{
    int a[100], n, i, sum = 0, avg;
    printf("enter size of array:");
    scanf("%d", &n);
    if (n < 100)
    {
        printf("enter array-\n");
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (i = 1; i <= n; i++)
        {
            sum = sum + a[i];
        }
        avg = sum / n;
        printf("sum of array is %d\n", sum);
        printf("avg of array is %d\n", avg);
    }
    else
    {
        printf("insufficient size");
    }
    return 0;
}
