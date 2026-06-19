// Write a program to Find maximum occurring character.
#include <stdio.h>

int main()
{
    char str[100];
    int i, j, count;
    int max = 0;
    char maxChar;

    printf("Enter the string: ");
    gets(str);
    // char pick ho ga then baki char se check kra ga agr same hua to count ho jaya ga
    // then store ho ga amx me agr nect count max se jada hua to replace ho jaya ga
    for (i = 0; str[i] != '\0'; i++)
    {
        count = 1;

        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
            {
                count++;
            }
        }

        if (count > max)
        {
            max = count;
            maxChar = str[i];
        }
    }

    printf("Maximum occurring character: %c\n", maxChar);
    printf("It appears %d times", max);

    return 0;
}
