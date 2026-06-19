// Write a program to Find first repeating character.
#include <stdio.h>

int main()
{
    char str[100];
    int i, j;

    printf("Enter the string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = i + 1; str[j] != '\0'; j++)//yha i+1 isliye kiya kyuki hume i ke baad ka check karna ha
        {
            if (str[i] == str[j])
            {
                printf("First repeating character: %c", str[i]);
                return 0;
            }
        }
    }

    printf("No repeating character found");

    return 0;
}
