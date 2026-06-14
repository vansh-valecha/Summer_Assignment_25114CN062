//Write a program to Sort array in descending order. 

#include <stdio.h>
#include <stdlib.h>

void input(int a[], int n)
{
    int i;

    printf("Enter array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void output(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void sortDescending(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int *a, n;

    printf("Enter size of array: ");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    input(a, n);
    sortDescending(a, n);
    printf("Array in descending order:\n");
    output(a, n);
    free(a);
    return 0;
}
