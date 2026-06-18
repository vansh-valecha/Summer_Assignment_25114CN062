// Write a program to Remove spaces from string.
#include <stdio.h>

int main()
{
    char str[100];
    int i, j = 0;
    // string ka sara char ko check kra ga agar space hoga to skip kra ga aur baki char ko copy kra ga
    printf("Enter the string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';

    printf("String after removing spaces: %s", str);

    return 0;
}
