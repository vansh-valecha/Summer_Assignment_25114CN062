// Write a program to Merge two sorted arrays
//  Write a program to Merge two sorted arrays.
#include <stdio.h>

int main()
{
    int a[10], b[10], c[20];
    int n1, n2, i, j, temp;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter first sorted array: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter second sorted array: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
        c[n1 + i] = b[i];
    }

    // Sort merged array
    for (i = 0; i < n1 + n2; i++)
    {
        for (j = i + 1; j < n1 + n2; j++)
        {
            if (c[i] > c[j])
            {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    printf("Merged sorted array: ");
    for (i = 0; i < n1 + n2; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}
