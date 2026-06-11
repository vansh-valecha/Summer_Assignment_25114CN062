//write a program to reverse an array.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, *a, temp, i, start, end;
    printf("enter size of array:");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    printf("enter array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    //fix the starting & ending position & swap the element until start is less than end(basically jab tak beach me nahi aa jate)
    start = 0;
    end = n - 1;
    while (start < end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
    printf("reverse array:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
