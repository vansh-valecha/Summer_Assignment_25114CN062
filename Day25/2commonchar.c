//Write a program to Find common characters in strings

#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i, j, k, repeat;

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    printf("Common characters: ");

    for (i = 0; str1[i] != '\0'; i++)
    {
        repeat = 0;

        // Check kra ga char phele print to nhi hua ha
        for (k = 0; k < i; k++)
        {
            if (str1[i] == str1[k])
            {
                repeat = 1;
                break;
            }
        }

        if (repeat == 0)
        {
            for (j = 0; str2[j] != '\0'; j++)
            {
                if (str1[i] == str2[j])
                {
                    printf("%c ", str1[i]);
                    break;
                }
            }
        }
    }

    return 0;
}
