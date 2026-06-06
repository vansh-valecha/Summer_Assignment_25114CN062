#include<stdio.h>

int main()
{
    int i,j;
     for (i = 5; i >= 1; i--)
    {
        for (j = i; j <= 4; j++)
        {
            printf(" ");
        }
        for (j = i*2-1; j >=  1; j--)
        {
            printf("*");
        }
        printf("\n");
    }
}
