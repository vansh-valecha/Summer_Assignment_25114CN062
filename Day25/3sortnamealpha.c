//Write a program to Sort names alphabetically. 
// Write a program to sort names alphabetically.
#include <stdio.h>
#include <string.h>

int main()
{
    char names[10][50], temp[50];//take 10 names
    int n, i, j;

    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar(); // Remove newline left by scanf()

    printf("Enter names:\n");
    for (i = 0; i < n; i++)
    {
        gets(names[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(names[i], names[j]) > 0)//agr bad ka name chhota ha to swap kra ga
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}
