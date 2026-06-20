//Write a program to Remove duplicate characters.
#include <stdio.h>

int main()
{
    char str[100];
    int i, j, k;

    printf("Enter the string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
            {
                for (k = j; str[k] != '\0'; k++)
                {
                    str[k] = str[k + 1];
                }

                j--;//replace place so that next time it must check
            }
        }
    }

    printf("After removing duplicates: %s", str);

    return 0;
}
