//Write a program to Rotate array right. 
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
//it will print the array after right rotation
void output(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
//first store the last element in temp variable then shift the element from right to left and finally store the temp variable in first index
void rotrig(int a[], int n)
{
    int i, temp;
    temp = a[n - 1];
    for (i = n - 1; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = temp;
    printf("array after right rotation:");
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
    rotrig(a, n);
    free(a);
    return 0;
}
