#include <stdio.h>
int main()
{
    int i, j, n, c;
    printf("enter no of rows:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        c = 65;
        for (j = 1; j <= i; j++)
        {
            printf("%c", c);
            c++;
        }
        printf("\n");
    }
    return 0;
}
