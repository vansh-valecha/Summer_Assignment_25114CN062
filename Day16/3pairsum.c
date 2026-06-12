#include <stdio.h>
#include <stdlib.h>

void input(int a[], int n)
{
    int i;
    printf("enter array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int main()
{
    int n, *a, t, i, j, found = 0;
    printf("enter size of array:");
    scanf("%d", &n);
    // locate the memory for array of size n
    a = (int *)malloc(sizeof(int) * n);
    input(a, n);
    printf("enter the target sum:");
    scanf("%d", &t);
    //outer loop give index & inner loop compare each index with remaining elements 
    //& if pair founds then it will print it
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == t)
            {
                printf("%d+%d=%d\n", a[i], a[j], t);
                found = 1;
            }
        }
    }
    if (found == 0)
    {
        printf("no pair found");
    }
    free(a);
    return 0;
}
