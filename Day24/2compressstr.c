//Write a program to Compress a string.
#include <stdio.h>

int main()
{
    char str[100];
    int i = 0, count;

    printf("Enter the string: ");
    gets(str);

    printf("Compressed string: ");
//string me char apne se aga wle ko check kra ga agr wo same ho ga to count++ ho jaya ga 
    while (str[i] != '\0')
    {
        count = 1;

        while (str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        printf("%c%d", str[i], count);
        i++;
    }

    return 0;
}
