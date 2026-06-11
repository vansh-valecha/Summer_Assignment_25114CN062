//Write a program to Rotate array left. 
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
//it will print the array after left rotation
void output(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void rotlef(int a[], int n)
{
    int temp, i;
    temp = a[0];
    for (i = 0; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = temp;
    printf("array after left rotation:");
    output(a, n);
}

int main()
{
    int n, *a;
    printf("enter size of array:");
    scanf("%d", &n);
    // locate the memory for array of size n
    a = (int *)malloc(sizeof(int) * n);
    input(a, n);
    rotlef(a, n);
    free(a);
    return 0;
}
