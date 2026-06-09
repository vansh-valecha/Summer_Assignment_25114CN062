//Write a program to Input and display array. 
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int *a, i, n;
    printf("enter size of array:");
    scanf("%d", &n);
    //it give the memory at run time or how much u want only that 
    a=(int*)malloc(sizeof(int)*n);

        for (i = 1; i <= n; i++)
        {
            printf("enter %d term of array:", i);
            scanf("%d", &a[i]);
        }
        for (i = 1; i <= n; i++)
        {
            printf("%d term of array is %d\n", i, a[i]);
        }
        free(a);
      return 0;
    }
