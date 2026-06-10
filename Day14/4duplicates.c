//Write a program to Find duplicates in array. 
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, i, j, n, count, duplFound = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    printf("Enter array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Duplicate elements:\n");
    for (i = 0; i < n; i++)
    {
        count = 1;
        // Check if this element was already counted before
        int alreadyChecked = 0;
        for (j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                alreadyChecked = 1;
                break;
            }
        }

        if (alreadyChecked)
        {
            continue;
        }

        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }

        if (count > 1)
        {
            printf("%d appears %d times\n", a[i], count);
            duplFound = 1;
        }
    }

    if (!duplFound)
    {
        printf("No duplicate elements found\n");
    }

    free(a);
    return 0;
}
