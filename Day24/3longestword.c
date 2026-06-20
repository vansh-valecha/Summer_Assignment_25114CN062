//Write a program to Find longest word
#include <stdio.h>

int main()
{
    char str[100], longest[100];
    int i = 0, j;
    int start = 0, length = 0;
    int maxStart = 0, maxLength = 0;

    printf("Enter a sentence: ");
    gets(str);

    while (1)
    {
        if (str[i] != ' ' && str[i] != '\0')
        {
            length++;
        }
        else
        {
            if (length > maxLength)
            {
                maxLength = length;
                maxStart = start;
            }

            length = 0;
            start = i + 1;
        }

        if (str[i] == '\0')
        {
            break;
        }

        i++;
    }

    for (j = 0; j < maxLength; j++)
    {
        longest[j] = str[maxStart + j];
    }

    longest[j] = '\0';

    printf("Longest word: %s\n", longest);
    printf("Length: %d", maxLength);

    return 0;
}
