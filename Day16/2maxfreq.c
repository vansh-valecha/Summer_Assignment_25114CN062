#include <stdio.h>
#include <stdlib.h>
// it will take the input array from user
void input(int a[], int n)
{
    int i;
    printf("enter array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
int maxfreq(int a[], int n)
{
    int i, j, count, maxCount = 0, maxElement;
    for (i = 0; i < n; i++)
    {
        count = 0;

        for (j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            maxElement = a[i];
        }
    }

    printf("Maximum frequency element is: %d\n", maxElement);
    printf("Frequency: %d", maxCount);
}

int main()
{
    int n, *a;
    printf("enter size of array:");
    scanf("%d", &n);
    // locate the memory for array of size n
    a = (int *)malloc(sizeof(int) * n);
    input(a, n);
    maxfreq(a, n);
    free(a);
    return 0;
}
