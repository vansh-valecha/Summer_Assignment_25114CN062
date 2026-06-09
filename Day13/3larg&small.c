// Write a program to Find largest and smallest element.
#include <stdio.h>

int main()
{
    int i, n, a[100], sl, lr;
    // it take how many element in an array
    printf("enter size of array:");
    scanf("%d", &n);
    if (n < 100)
    {
        // take the input
        printf("enter array-");
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        // set small & large no for compare with other
        sl = a[1];
        lr = a[1];
        for (i = 1; i <= n; i++)
        {
            if (a[i] <= sl)
            {
                sl = a[i];
            }
            if (a[i] >= lr)
            {
                lr = a[i];
            }
        }
        // output
        printf("largest element in array is %d\n", lr);
        printf("small element in array is %d", sl);
    }
    else
    {
        printf("out of range");
    }
    return 0;
}
